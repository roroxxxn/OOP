#include<iostream>
#include<vector>
#include "Text.h"
#include <fstream>
#include<string>
#include<cmath>
#include <sstream>
#include<stack>

using namespace std;

/*
 * 문자열이 숫자인지 아닌지 판별하는 함수
 * str이 숫자이면 정수형 숫자로 변환하여 리턴하고
 * 숫자가 아니라 문자이면 0을 리턴한다.
 */
bool is_digit(string str) { 
	return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}

int main() {

	vector<string> input;	// text.txt 파일의 내용을 저장
	string instruction;		// 입력받은 명령어를 저장

	// 파일 입출력 함수를 통해 text.txt 파일의 내용을 input 변수에 저장한다.
	ifstream fin;
	fin.open("test.txt");
	string str;
	while (!fin.eof()) {
		fin >> str;
		input.push_back(str);
	}
	fin.close();

	int vsize = input.size(); // 입력받은 텍스트의 길이

	Text* instance;					// Text형 객체 변수를 포인터형 변수 형태로 생성
	instance = Text::getInstance(); // getInstance함수 호출을 통한 Text 객체 생성
	instance->setter(input);		// 입력받은 텍스트를 생성한 객체에 넣어준다.

	vector<string> cmsg; // 콘솔 메시지


	int j = 0;		// 페이지 출력 시 맨 앞 단어의 인덱스 번호
	int count = 0;	// textprint 함수의 리턴 값을 저장할 변수
	int dre = 0;	// del 함수의 리턴 값을 저장할 변수
	int ire = 0;	// insert 함수의 리턴 값을 저장할 변수


	while (1) {
		/*
		 * 1. 현재 페이지를 출력하고 명령어 입력받기.
		 */
		count = instance->textprint(j, vsize); // 현재 페이지를 출력하고 textprint 함수는 n을 입력했을 때 출력해야하는 인덱스의 시작을 리턴한다.
		cout << "--------------------------------------------------------------------------------\n";
		cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료\n";
		cout << "--------------------------------------------------------------------------------\n";
		cout << "(콘솔메세지) ";
		for (int i = 0; i < cmsg.size(); i++) { // 입력한 명령의 결과에 따른 콘솔 메세지를 출력한다.
			cout << cmsg[i];
		}
		cout << "\n";
		cout << "--------------------------------------------------------------------------------\n";
		cout << "입력:";
		cin >> instruction;
		cout << "--------------------------------------------------------------------------------\n";

		for (int i = cmsg.size() - 1; i >= 0; i--) { // 다음 명령어의 실행결과를 위해 콘솔 메세지를 초기화한다.
			cout << i << endl;
			cmsg.pop_back();
		}

		/*
		 * 2. 입력받은 명령어 분석하기.
		 */
		char n0 = instruction[0];	// 명령어의 첫 문자를 저장한다.
		vector<string> words;		// 명령어의 세부적인 요구사항을 담을 벡터 변수

		if (n0 == 'i' || n0 == 'd' || n0 == 's' || n0 == 'c') { // 명령어의 첫 문자를 통해 어떤 명령을 실행할 것인지 파악한다.
			instruction.erase(0, 2);	// 여는 괄호와,
			instruction.pop_back();		// 닫는 괄호를 제거한 명령어를 뽑아낸다.
			stringstream f(instruction);
			string s;
			while (getline(f, s, ',')) // 쉼표 단위로 명령어를 분리하여 words 변수에 저장한다.
			{
				words.push_back(s);
			}
		}

		/*
		 * <명령어에 따른 변수 목록>
		 */
		string from, to;						// 변경(c) 명령문에서 사용될 변수
		string sch;								// 검색(s) 명령문에서 사용될 변수
		int r, c;								// 삭제(d) 명령문에서 사용될 변수
		int ir, ic;								// 삽입(i) 명령문에서 사용될 변수
		string inserted;						// 삽입(i) 명령문에서 사용될 변수
		ofstream write("test.txt", ios::trunc);	// 저장(t) 명령문에서 사용될 함수 (trunc=오픈하고자 하는 파일이 이미 있는 경우, 기존의 파일을 삭제하고 다시 만든다.)


		/*
		 * 3. 분석한 명령어에 따른 실행
		 */
		switch (n0) {

		// < 작업 내용: 다음페이지 출력 >
		case 'n':
			if (count == vsize) { // 경우 1) 현재 페이지가 마지막 페이지일 때
				cmsg.push_back("현재 페이지가 마지막 페이지 입니다.");
			}
			else { // 경우 2) 마지막 페이지가 아닐 때
				int r = instance->bremainder(count, vsize); // 현재 페이지의 뒤에 남은 행의 수를 알아낸다.

				if (r >= 20) { // 경우 2-1) 현재 페이지 뒤에 남은 행이 20줄 이상일 때
					j = count; // 다음 페이지 맨 앞 단어의 인덱스인 변수 j는 
							   // textprint의 리턴 값(현재 페이지 다음(n)에 출력해야 할 첫번째 단어의 인덱스 번호)인 count가 된다.
				}
				else {	// 경우 2-2) 현재 페이지 뒤에 남은 행이 20줄 보다 작을 때
						// 현재 페이지의 맨 마지막 인덱스부터 시작하여 (20행-뒤에 남은 행)행 만큼 앞에 있는 단어의 인덱스를 계산한다. 

					int size = 0;		// 한 행의 사이즈를 검사하기 위한 변수
					int row = 0;		// 몇 행을 반복했는지 검사하기 위한 변수
					int p = count - 1;	// p는 현재 페이지의 맨 마지막 인덱스이다.

					while (row < 20 - r) {				// (20행-뒤에 남은 행)행 만큼 반복한다.
						size += input[p].size() + 1;	// 공백 한 칸의 길이와 단어 하나의 길이를 누적해서 더해준다.
						if (size > 75) {				// 한 행당 75바이트 까지 출력할 수 있으므로 size가 75를 넘어가면
							size = 0;					// size를 0으로 초기화하고
							row++;						// row를 1 증가시키고
							p++;						// 검사하는 단어의 인덱스는 다시 한 칸 뒤로 밀려나게 된다.
						}
						p--;	// 반복할 때마다 단어의 인덱스를 앞으로 한 칸씩 전진시킨다.
					}
					j = p + 1;	// 반복을 모두 끝내면 변수 j는 p + 1이 된다.(바로 윗 줄에서 마지막 반복시에 불필요한 p-- 를 실행하기 때문)
				}
			}
			break;

		// < 작업 내용: 이전페이지 출력 >
		case 'p': 
			if (j == 0) { // 경우 1) 현재 페이지가 첫번째 페이지일 때
				cmsg.push_back("현재 페이지가 첫번째 페이지 입니다.");
			}
			else { // 경우 2) 현재 페이지가 첫번째 페이지가 아닐 때
				int r = instance->fremainder(j); // 현재 페이지의 앞에 남아있는 행의 수를 알아낸다.

				if (r >= 20) {	// 경우 2-1) 현재 페이지 앞에 남아있는 행이 20줄 이상일 때
								// 이전 페이지 맨 마지막 단어의 인덱스부터 시작하여 20행 만큼 앞에 있는 단어의 인덱스를 계산한다.

					int size = 0;	// 한 행의 사이즈를 검사하기 위한 변수
					int row = 0;	// 몇 행을 반복했는지 검사하기 위한 변수
					int p = j - 1;	// p는 이전 페이지의 맨 마지막 인덱스이다.

					while (row < 20) {					// 20행 만큼 반복한다.
						size += input[p].size() + 1;	// 공백 한 칸의 길이와 단어 하나의 길이를 누적해서 더해준다.
						if (size > 75) {				// 한 행당 75바이트 까지 출력할 수 있으므로 size가 75를 넘어가면
							size = 0;					// size를 0으로 초기화하고
							row++;						// row를 1 증가시키고
							p++;						// 검사하는 단어의 인덱스는 다시 한 칸 뒤로 밀려나게 된다.
						}
						p--;	// 반복할 때마다 단어의 인덱스를 앞으로 한 칸씩 전진시킨다.
					}
					j = p + 1;	// 반복을 모두 끝내면 변수 j는 p + 1이 된다. (바로 윗 줄에서 마지막 반복시에 불필요한 p-- 를 실행하기 때문) 
				}
				else {	// 경우 2-2) 현재 페이지 앞에 남아있는 행이 20줄 보다 작을 때
						// 앞에 남아있는 텍스트는 전체 텍스트의 앞부분에 해당하므로 변수 j는 0이 된다.
					j = 0;
				}
			}

			break;

		// < 작업 내용: 삽입 >
		case 'i': // 작업 내용: 삽입
			// 경우 1) 행과 열의 입력이 숫자가 아니거나, 
			//         삽입할 단어가 74바이트 보다 크면(띄어쓰기 공백을 포함하기 때문에 75가 아니라 74) 잘못된 입력이다.
			if (is_digit(words.at(0)) == false || is_digit(words.at(1)) == false || (words.at(2)).size() > 74) { 
				cmsg.push_back("잘못된 인덱스 입력입니다. 다시 입력해주세요.");
				break;
			}

			// 경우 2) 행과 열의 입력이 숫자이고 삽입할 단어가 74이하인 경우
			ir = stoi(words.at(0));						// 삽입할 행을 문자열에서 정수형으로 변환한다.
			ic = stoi(words.at(1));						// 삽입할 열을 문자열에서 정수형으로 변환한다.
			inserted = words.at(2);						// 삽입할 단어를 저장한다.
			ire = instance->insert(ir, ic, inserted, j);// insert 함수를 호출하여 리턴 값을 저장한다.
			if (ire == 0) {								// 범위를 초과한 인덱스 입력인 경우에는 insert 함수가 0을 리턴한다.
				cmsg.push_back("잘못된 입력입니다. 다시 입력해주세요.");
				break;
			}
			vsize++; // 단어 하나를 추가했으므로 텍스트의 길이를 1 증가시킨다.
			break;

		// < 작업 내용: 삭제 >
		case 'd':
			if (is_digit(words.at(0)) == false || is_digit(words.at(1)) == false) { // 경우 1) 행과 열의 입력이 숫자가 아니면 잘못된 입력이다.
				cmsg.push_back("잘못된 인덱스 입력입니다. 다시 입력해주세요.");
				break;
			}

			// 경우 2) 행과 열의 입력이 숫자일 때
			r = stoi(words.at(0));			// 삭제할 단어의 행을 저장한다.
			c = stoi(words.at(1));			// 삭제할 단어의 열을 저장한다.
			dre = instance->del(r, c, j);	// del 함수를 호출하여 리턴 값을 저장한다.
			if (dre == 0) {					// 범위를 초과한 인덱스 입력인 경우에는 del 함수가 0을 리턴한다.
				cmsg.push_back("잘못된 인덱스 입력입니다. 다시 입력해주세요.");
				break;
			}
			vsize--; // 단어 하나를 삭제했으므로 텍스트의 길이가 1 감소시킨다.
			break;

		// < 작업 내용: 변경(완료) >
		case 'c': 
			from = words.at(0);			// 1) 변경되어야하는 단어를 저장한다.
			to = words.at(1);			// 2) 대체되는 단어를 저장한다.
			instance->change(from, to);	// 3) change 함수를 호출한다.
			break;

		// < 작업 내용: 찾기 >
		case 's': 
			sch = words.at(0);			// 1) 명령어에서 찾고자 하는 단어를 sch 변수에 저장한다.
			j = instance->search(sch);	// 2) search 함수를 호출한다.
			break;

		// < 작업 내용: 저장 후 종료 >
		// * 주의: 콘솔창을 종료할 때 x버튼을 누르면 안되고 t입력을 통해서 종료해야만 한다!

		case 't': 
			if (write.is_open()) { // 1) 변경된 내용을 파일에 저장한다.(기존의 파일에 원래있던 내용을 지우고 다시 쓰는 방식)
				for (int i = 0; i < vsize; i++) {
					write << instance->at(i) << " ";
				}
				write.close();
			}
			goto EXIT; // 2) while문 빠져나오기
			break;

		// < 지정되지 않은 문자를 입력한 경우 >
		default: 
			cmsg.push_back("잘못된 명령어 입니다. 다시 입력해주세요."); // 오류메세지를 콘솔메시지 변수에 저장한다.
			break;

		}

	}
EXIT:
	cout << "변경사항이 저장되었습니다.";

	return 0;
}