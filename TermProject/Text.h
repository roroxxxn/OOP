#ifndef Text_H_
#define Text_H_
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Text {
private:

	/*
	 * ������
	 * �ܺο��� �ν��Ͻ��� ������ �� ������ private ������ �����ϰ� �����Ͽ���.
	 * private ������ �����ڰ� �����ϹǷ� �ܺο��� Text()�� ȣ���� �� ����.
	 */
	Text() {};

	// �̱��� ��ü�� �����Ǿ����� ���θ� ��Ÿ���� ����
	static bool instanceFlag;

	// �̱��� ��ü
	static Text* m;

	// �ؽ�Ʈ ������ ���� private ��� ����
	vector<string> txt;

public:

	// �̱��� ��ü�� ��ȯ�� ����Լ�
	static Text* getInstance();

	// �Ҹ���, instanceFlag�� false�� ����
	virtual ~Text() {
		instanceFlag = false;
	};

	int insert(int ir, int ic, string inserted, int j);	// ���� ��ɾ �����ϴ� �Լ�
	int del(int r, int c, int j);						// ���� ��ɾ �����ϴ� �Լ�
	void change(string from, string to);				// ���� ��ɾ �����ϴ� �Լ�
	int search(string sch);								// Ž�� ��ɾ �����ϴ� �Լ�
	int textprint(int j, int vs);						// �ؽ�Ʈ ����� ���� �Լ�
	void setter(vector<string>& k);						// �ؽ�Ʈ ������ set�ϴ� �Լ�
	int fremainder(int j);								// ���� â�� ��µ� �ؽ�Ʈ�� �տ� �����ִ� ���� ��
	int bremainder(int j, int vs);						// ���� â�� ��µ� �ؽ�Ʈ�� �ڿ� �����ִ� ���� ��
	string at(int i);									// ��ü �ؽ�Ʈ �߿��� i��° �ε����� ���� �����ϴ� �Լ�

};
#endif /* Text_H_ */