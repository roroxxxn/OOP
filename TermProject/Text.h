#ifndef Text_H_
#define Text_H_
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Text {
private:

	/*
	 * 생성자
	 * 외부에서 인스턴스를 생성할 수 없도록 private 영역에 정의하고 구현하였다.
	 * private 영역에 생성자가 존재하므로 외부에서 Text()를 호출할 수 없다.
	 */
	Text() {};

	// 싱글턴 객체가 생성되었는지 여부를 나타내는 변수
	static bool instanceFlag;

	// 싱글턴 객체
	static Text* m;

	// 텍스트 내용을 담을 private 멤버 변수
	vector<string> txt;

public:

	// 싱글턴 객체를 반환할 멤버함수
	static Text* getInstance();

	// 소멸자, instanceFlag를 false로 변경
	virtual ~Text() {
		instanceFlag = false;
	};

	int insert(int ir, int ic, string inserted, int j);	// 삽입 명령어를 실행하는 함수
	int del(int r, int c, int j);						// 삭제 명령어를 실행하는 함수
	void change(string from, string to);				// 변경 명령어를 실행하는 함수
	int search(string sch);								// 탐색 명령어를 실행하는 함수
	int textprint(int j, int vs);						// 텍스트 출력을 위한 함수
	void setter(vector<string>& k);						// 텍스트 내용을 set하는 함수
	int fremainder(int j);								// 현재 창에 출력된 텍스트의 앞에 남아있는 행의 수
	int bremainder(int j, int vs);						// 현재 창에 출력된 텍스트의 뒤에 남아있는 행의 수
	string at(int i);									// 전체 텍스트 중에서 i번째 인덱스의 값을 리턴하는 함수

};
#endif /* Text_H_ */