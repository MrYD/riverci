#include <iostream>
#include <conio.h>
using namespace std;
int turnC;
int Sp[8][8];
int Fu[8][8];
int Fux[8][8];
int pass;
int turn;
int num;
int check;
int x;
int y;
int k;
char *ishi;
int SpC[8][8];
int FuC[8][8];
int Hyoka[8][8];
int turnCC;
int aiteCC;
int space[8][8];
int not = 1000000;
int hyoka;
int a;
int number;
int nokori;
int mode;

void test(int H[8][8]){
	for (int i = 0; i < 8; i++){
		cout << "\n";
		for (int j = 0; j <8; j++){
			if (H[i][j]<999999)
				cout << H[i][j];
			else cout << "�E";
			cout << " ";
		}
	}
	cout << "\n";
}


char *Ishi(int a)
{
	if (a == 1)
		ishi = "��";
	if (a == 2)
		ishi = "��";
	if (a == 0)
		ishi = "";
	return ishi;
}

int Kosuu(int a, int A[8][8]){ //a�̌��𐔂���
	int k = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){
			if (A[i][j] == a)
				k++;
		}
	}
	return k;
}

int Tesuu(int A[8][8]){ //0�ȊO�̗v�f���𐔂���
	int k = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){
			if (A[i][j] != 0)
				k++;
		}
	}
	return k;
}
void Fukusei(int A[8][8], int B[8][8])
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){
			B[i][j] = A[i][j];
		}
	}
}

void Reset(int A[8][8])
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){
			A[i][j] = 0;
		}
	}
}

int Aite(int a)
{
	if (a == 1) return 2;
	if (a == 2) return 1;
	if (a != 1 && a != 2)return 0;
}

void Explore(int A[8][8], int B[8][8]) //���ʂ̕\��
{
	x = Kosuu(1, A);
	y = Kosuu(2, A);
	cout << "��player1 (" << x << ")" << "\n��player2 (" << y << ")";
	for (int i = 0; i < 8; i++){
		cout << "\n";
		for (int j = 0; j <8; j++){
			cout << Ishi(A[i][j]);
			if (B[i][j] != 0)
			{
				if (B[i][j] < 10)
					cout << " " << B[i][j];
				else
					cout << B[i][j];
			}
			if ((A[i][j] == 0) && (B[i][j] == 0))
				cout << "�E";
		}
	}
	cout << "\n";
}



int Okiba(int t, int A[8][8], int B[8][8]) //OKiba(�v���[���[,����,�u����j���@�u����
{   
	Reset(space);
	Reset(B);
	int count;
	int a;
	if (t == 1)  a = 2;
	if (t == 2)  a = 1;

	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){

			if (A[i][j] == 0) {

				count = 0;    //�E�`�F�b�N
				check = a;
				while ((check == a) && ((i + count)< 7))
				{
					count++;
					check = A[i + count][j];
				}
				if ((check == t) && (count > 1))
					space[i][j] = t;


				count = 0; // ���`�F�b�N
				check = a;
				while ((check == a) && (0 < (i - count)))
				{
					count++;
					check = A[i - count][j];
				}
				if ((check == t) && (count > 1))
					space[i][j] = t;


				count = 0; //��`�F�b�N
				check = a;
				while ((check == a) && (0 < (j - count)))
				{
					count++;
					check = A[i][j - count];
				}
				if ((check == t) && (count > 1))
					space[i][j] = t;

				count = 0;  //���`�F�b�N
				check = a;
				while ((check == a) && ((j + count) <7))
				{
					count++;
					check = A[i][j + count];
				}
				if ((check == t) && (count > 1))
					space[i][j] = t;

				count = 0; //�E���`�F�b�N
				check = a;
				while ((check == a) && ((i + count)< 7) && ((j + count) <7))
				{
					count++;
					check = A[i + count][j + count];
				}
				if ((check == t) && (count > 1))
					space[i][j] = t;

				count = 0; //�����`�F�b�N
				check = a;
				while ((check == a) && (0 < (i - count)) && ((j + count)<7))
				{
					count++;
					check = A[i - count][j + count];
				}
				if ((check == t) && (count > 1))
					space[i][j] = t;

				count = 0;  //�E��`�F�b�N
				check = a;
				while ((check == a) && ((i + count) <7) && (0 < (j - count)))
				{
					count++;
					check = A[i + count][j - count];
				}
				if ((check == t) && (count > 1))
					space[i][j] = t;

				count = 0; //�E��`�F�b�N
				check = a;
				while ((check == a) && (0 <(i - count)) && (0 <(j - count)))
				{
					count++;
					check = A[i - count][j - count];

				}
				if ((check == t) && (count > 1))
					space[i][j] = t;
			}
		}
	}

	count = 0;

	for (int i = 0; i < 8; i++){ //B�̍쐬
		for (int j = 0; j <8; j++){
			if (space[i][j] == t)
			{
				count++;
				B[i][j] = count;
			}
			else
				B[i][j] = 0;
		}
	}
	return count;
}
int Judge(int A[8][8], int t){
	int judge = 0;
	int B[8][8];
	if (Okiba(1, A, B) == 0 && Okiba(2, A, B) == 0)
	{
		x = Kosuu(t, A);
		y = Kosuu(Aite(t), A);
		if (x>y) judge = 1;
		if (x<y) judge = 2;
		if (x == y)judge = 3;
	}
	return judge;
}


int Chakusyu(int t, int u, int A[8][8], int B[8][8]) //	Chakusyu(�v���[���[,�ԍ�,����,�u����j���@����
{
	int b = 0;
	int count;
	if (t == 1)  a = 2;
	if (t == 2)  a = 1;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){
			if (B[i][j] == u)
			{
				A[i][j] = t;

				count = 0;    //�E�`�F�b�N
				check = a;
				while ((check == a) && (i + count< 7))
				{
					count++;
					check = A[i + count][j];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					A[i + k][j] = t;
					b++;
				}

				count = 0; // ���`�F�b�N
				check = a;
				while ((check == a) && (0 < i - count))
				{
					count++;
					check = A[i - count][j];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					A[i - k][j] = t;
					b++;
				}

				count = 0; //��`�F�b�N
				check = a;
				while ((check == a) && (0 < j - count))
				{
					count++;
					check = A[i][j - count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					A[i][j - k] = t;
					b++;
				}
				count = 0;  //���`�F�b�N
				check = a;
				while ((check == a) && (j + count <7))
				{
					count++;
					check = A[i][j + count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					A[i][j + k] = t;
					b++;
				}
				count = 0; //�E���`�F�b�N
				check = a;
				while ((check == a) && (i + count<7) && (j + count <7))
				{
					count++;
					check = A[i + count][j + count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					A[i + k][j + k] = t;
					b++;
				}

				count = 0; //�����`�F�b�N
				check = a;
				while ((check == a) && (0 < i - count) && (j + count <7))
				{
					count++;
					check = A[i - count][j + count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					A[i - k][j + k] = t;
					b++;
				}

				count = 0;  //�E��`�F�b�N
				check = a;
				while ((check == a) && (i + count <7) && (0 < j - count))
				{
					count++;
					check = A[i + count][j - count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					A[i + k][j - k] = t;
					b++;
				}

				count = 0; //�E��`�F�b�N
				check = a;
				while ((check == a) && (0 < i - count) && (0 < j - count))
				{
					count++;
					check = A[i - count][j - count];

				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					A[i - k][j - k] = t;
					b++;
				}
			}
		}
	}
	return b;
}

void Ginmi(int a, int b){          //a�Ԗڂ̃}�X��Hyoka��b��������
	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){
			if (Sp[i][j] == a)
				Hyoka[i][j] += b;
		}
	}
}



int Kaihoudo(int u, int t, int A[8][8], int B[8][8])

{
	int K = 0;
	int count;
	int a;
	if (t == 1)  a = 2;
	if (t == 2)  a = 1;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){
			if (B[i][j] == u)
			{
				count = 0;    //�E�`�F�b�N
				check = a;
				while ((check == a) && (i + count< 7))
				{
					count++;
					check = A[i + count][j];
				}
				if ((check == t) && (count > 1))
				{
					K++;
					for (int k = 1; k <= count - 1; k++)
					{
						if (j>0){
							if (A[i + k - 1][j + 1] == 0) K++;
							if (A[i + k][j + 1] == 0) K++;
							if (A[i + k + 1][j + 1] == 0) K++;
						}
						if (j<7){
							if (A[i + k - 1][j - 1] == 0) K++;
							if (A[i + k][j - 1] == 0) K++;
							if (A[i + k + 1][j - 1] == 0) K++;
						}
					}
				}

				count = 0; // ���`�F�b�N
				check = a;
				while ((check == a) && (0 < i - count))
				{
					count++;
					check = A[i - count][j];
				}
				if ((check == t) && (count > 1))
				{
					K++;
					for (int k = 1; k <= count - 1; k++)
					{
						if (j>0){
							if (A[i - k - 1][j + 1] == 0) K++;
							if (A[i - k][j + 1] == 0) K++;
							if (A[i - k + 1][j + 1] == 0) K++;
						}
						if (j<7){
							if (A[i - k - 1][j - 1] == 0) K++;
							if (A[i - k][j - 1] == 0) K++;
							if (A[i - k + 1][j - 1] == 0) K++;
						}
					}
				}

				count = 0; //��`�F�b�N
				check = a;
				while ((check == a) && (0 < j - count))
				{
					count++;
					check = A[i][j - count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					K++;
					for (int k = 1; k <= count - 1; k++)
					{
						if (i>0){
							if (A[i + 1][j - k - 1] == 0) K++;
							if (A[i + 1][j - k + 1] == 0) K++;
							if (A[i + 1][j - k] == 0) K++;
						}
						if (i<7){
							if (A[i - 1][j - k + 1] == 0) K++;
							if (A[i - 1][j - k] == 0) K++;
							if (A[i - 1][j - k - 1] == 0) K++;
						}
					}
				}

				count = 0;  //���`�F�b�N
				check = a;
				while ((check == a) && (j + count <7))
				{
					count++;
					check = A[i][j + count];
				}
				if ((check == t) && (count > 1)) {
					K++;
					for (int k = 1; k <= count - 1; k++)
					{
						if (i>0){
							if (A[i + 1][j + k - 1] == 0) K++;
							if (A[i + 1][j + k + 1] == 0) K++;
							if (A[i + 1][j + k] == 0) K++;
						}
						if (i<7){
							if (A[i - 1][j + k + 1] == 0) K++;
							if (A[i - 1][j + k] == 0) K++;
							if (A[i - 1][j + k - 1] == 0) K++;
						}
					}
				}
				count = 0; //�E���`�F�b�N
				check = a;
				while ((check == a) && (j + count<7) && (j + count <7))
				{
					count++;
					check = A[i + count][j + count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					if (A[i + k - 1][j + k - 1] == 0) K++;
					if (A[i + k][j + k - 1] == 0) K++;
					if (A[i + k + 1][j + k - 1] == 0) K++;
					if (A[i + k - 1][j + k] == 0) K++;
					if (A[i + k + 1][j + k] == 0) K++;
					if (A[i + k - 1][j + k + 1] == 0) K++;
					if (A[i + k][j + k + 1] == 0) K++;
					if (A[i + k + 1][j + k + 1] == 0) K++;
				}

				count = 0; //�����`�F�b�N
				check = a;
				while ((check == a) && (0 < i - count) && (j + count <7))
				{
					count++;
					check = A[i - count][j + count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					if (A[i - k - 1][j + k - 1] == 0) K++;
					if (A[i - k][j + k - 1] == 0) K++;
					if (A[i - k + 1][j + k - 1] == 0) K++;
					if (A[i - k - 1][j + k] == 0) K++;
					if (A[i - k + 1][j + k] == 0) K++;
					if (A[i - k - 1][j + k + 1] == 0) K++;
					if (A[i - k][j + k + 1] == 0) K++;
					if (A[i - k + 1][j + k + 1] == 0) K++;
				}

				count = 0;  //�E��`�F�b�N
				check = a;
				while ((check == a) && (i + count <7) && (0 < j - count))
				{
					count++;
					check = A[i + count][j - count];
				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					if (A[i + k - 1][j - k - 1] == 0) K++;
					if (A[i + k][j - k - 1] == 0) K++;
					if (A[i + k + 1][j - k - 1] == 0) K++;
					if (A[i + k - 1][j - k] == 0) K++;
					if (A[i + k + 1][j - k] == 0) K++;
					if (A[i + k - 1][j - k + 1] == 0) K++;
					if (A[i + k][j - k + 1] == 0) K++;
					if (A[i + k + 1][j - k + 1] == 0) K++;
				}

				count = 0; //�E���`�F�b�N
				check = a;
				while ((check == a) && (0 < i - count) && (0 < j - count))
				{
					count++;
					check = A[i - count][j - count];

				}
				if ((check == t) && (count > 1))
				for (int k = 1; k <= count - 1; k++)
				{
					if (A[i - k - 1][j - k - 1] == 0) K++;
					if (A[i - k][j - k - 1] == 0) K++;
					if (A[i - k + 1][j - k - 1] == 0) K++;
					if (A[i - k - 1][j - k] == 0) K++;
					if (A[i - k + 1][j - k] == 0) K++;
					if (A[i - k - 1][j - k + 1] == 0) K++;
					if (A[i - k][j - k + 1] == 0) K++;
					if (A[i - k + 1][j - k + 1] == 0) K++;
				}
			}
		}
	}
	return K;
}

int Sakiyomi(int hyoka, int turnCC, int aC, int A[8][8]) {
	int B[8][8];
	int S[8][8];
	int next_hyoka = 0;
	int this_hyoka = 0;
	int pre_hyoka = hyoka;
	int last_hyoka = not;
	Fukusei(A, B);
	k = Okiba(turnC, A, S);
	for (int n = 1; n <= k || (n == k + 1 && k == 0); n++)  //n�Ԗڂɂ������ꍇ
	{
		Fukusei(A, B);
		Okiba(turnCC, A, S);

		if (turnC == turnCC)
		{
			this_hyoka = Kaihoudo(n, turnCC, B, S);
			Chakusyu(turnCC, n, B, S);
			Okiba(Aite(turnCC), B, S);
			//	Explore(B,S);
			if (S[0][0] != 0 || S[0][7] != 0 || S[7][0] != 0 || S[7][7] != 0)//�p�������ꍇ�͎}�؂�
			{
				this_hyoka = 1000;
				if (aC != number) return this_hyoka;
			}
		
			if (aC > 1)
			{
				if (this_hyoka < 1000){
					next_hyoka = Sakiyomi(pre_hyoka + this_hyoka, Aite(turnCC), aC - 1, B); //���͑���̔�
					if (next_hyoka <= hyoka || hyoka == 0)  hyoka = next_hyoka; //�����̍őP���hyoka��
				}
			}
			if (last_hyoka >= this_hyoka)last_hyoka = this_hyoka;//�Ō�̏���
		}

		if (turnC != turnCC)
		{
			this_hyoka = -1 * Kaihoudo(n, turnCC, B, S);
			Chakusyu(turnCC, n, B, S);
			Okiba(Aite(turnCC), B, S);
			// Explore(B,S);
			if (S[0][0] != 0 || S[0][7] != 0 || S[7][0] != 0 || S[7][7] != 0)
				this_hyoka -= 1000;             //�p������Ɗ�����

			if (aC > 1)
			{
				if (this_hyoka < 1000){
					next_hyoka = Sakiyomi(pre_hyoka + this_hyoka, Aite(turnCC), aC - 1, B); //���͎����̔�
					if (next_hyoka >= hyoka || hyoka == 0)  hyoka = next_hyoka;//����̍őP���hyoka��
				}
			}
			if (last_hyoka <= this_hyoka || last_hyoka == not)last_hyoka = this_hyoka;
		}
		if (aC == number)  //���X�g
			Ginmi(n, this_hyoka + hyoka);

		k = Okiba(turnC, A, S); //for�̂��߂̃��Z�b�g
	}
	if (aC == 1) return hyoka + last_hyoka;//���[
	if (1<aC<number)return hyoka;//�r��
	if (aC == number) return 0;
}
int Yomikiri(int hyoka, int turnCC, int aC, int A[8][8]) {
	int B[8][8];
	int S[8][8];
	int next_hyoka = 0;
	int this_hyoka = 0;
	int last_hyoka = not;
	Fukusei(A, B);
	k = Okiba(turnC, A, S);
	for (int n = 1; n <= k || (n == k + 1 && k == 0); n++)  //n�Ԗڂɂ������ꍇ
	{
		Fukusei(A, B);
		Okiba(turnCC, A, S);
		Chakusyu(turnCC, n, B, S);
		switch (Judge(B, turnC))
		{
		case 1:this_hyoka = -10000; break;
		case 2:this_hyoka = 10000; break;
		case 3:this_hyoka = 1; break;
		case 0:{
				   next_hyoka = Yomikiri(hyoka, Aite(turnCC), aC - 1, B); //���[�v
				   if (turnC == turnCC && (next_hyoka <= hyoka || hyoka == 0))  hyoka = next_hyoka; //�����̍őP���hyoka��
				   if (turnC != turnCC && (next_hyoka >= hyoka || hyoka == 0))  hyoka = next_hyoka; //����̍őP���hyoka��
		}break;
		}
		if (aC == nokori)
		{
			Ginmi(n, this_hyoka + hyoka); //���X�g
			hyoka = 0;
		}
		k = Okiba(turnC, A, S);
	}
	if (this_hyoka != 0) return this_hyoka;//���[
	if (1<aC<nokori)return hyoka;//�r��
	if (aC == nokori) return 0;
}



int AI(int turn){
	cout << "CPU���l���܂�";

	Reset(Hyoka);
	hyoka = 0;
	number = 4;
	nokori = 11;

	if (Tesuu(Fu)>64 - nokori)
		Yomikiri(hyoka, turnC, nokori, Fu);
	else
	{
		Sakiyomi(hyoka, turnC, number, Fu);
		Hyoka[1][1] = 1000;
		Hyoka[1][6] = 1000;
		Hyoka[6][1] = 1000;
		Hyoka[6][6] = 1000;
	}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j <8; j++){

			if (Sp[i][j] == 0)             //�u���邩�ǂ���
				Hyoka[i][j] += not;
		}
	}
	test(Hyoka);
	int h = not;
	for (int i = 0; i < 8; i++){   //�]���̍ł��������}�X��Ԃ�
		for (int j = 0; j <8; j++){
			if (Hyoka[i][j]<h)
			{
				h = Hyoka[i][j];
				num = Sp[i][j];
			}
		}
	}
	return num;
}



int Daseki(){
	k = Tesuu(Sp);
	if (k == 0)
	{
		cout << "�u���܂���";
		cout << "\n";
		_getch;
	}

	else
	{
		if ((mode == 2 && turnC == 2) || (mode == 3 && turnC == 1)) num = 0;
		else{
			cout << "�����̔ԍ������";
			cin >> num;
			while ((num < 0) || (num > k))
			{
				cout << "�l���قȂ�܂�\n";
				cin >> num;
			}
		}
		if (num == 0)

		{
			Fukusei(Fu, Fux);
			num = AI(turnC);
			cout << num << "\n";
			Fukusei(Fux, Fu);
		}
		Chakusyu(turnC, num, Fu, Sp);
	}

	if (turnC == 1)
		turnC = 2;
	else
		turnC = 1;

	return turnC;
}


void Result()
{
	cout << "\n�y���ʁz\n";
	Explore(Fu, Sp);
	switch (Judge(Fu, 1)){
	case 1: if (mode == 3)
		cout << "\n��CPU�̏���";
			else
				cout << "\n��player1�̏���";
		break;
	case 2:if (mode == 2)
		cout << "\n��CPU�̏���";
		   else
			   cout << "\n��player2�̏���";
		break;
	case 3:cout << "\n���������ł�"; break;
	}
	int a;
	cin >> a;
}

int main()
{
	Reset(Fu);
	Fu[3][3] = 1;
	Fu[3][4] = 2;
	Fu[4][3] = 2;
	Fu[4][4] = 1;
	cout << "���o�[�V���n�߂܂�\n";
	cout << "\n���[�h��I��ł�������\n";
	cout << "\nplayer1 vs player2   -1\n"
		<< "player1 vs    CPU    -2\n"
		<< "    CPU vs player2   -3\n";
	cin >> mode;
	turnC = 2;
	Okiba(turnC, Fu, Sp);
	Explore(Fu, Sp);
	int pass = 0;
	int turn = 0;
	while (pass<2){
		turn++;
		cout << "\n�y" << turn << "��ځz";
		cout << Ishi(turnC) << "player" << turnC << "\n";

		int k = 0;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j <8; j++){
				if (Sp[i][j] != 0)
					k++;
			}
		}
		if (k == 0)
			pass++;
		else
			pass = 0;

		turnC = Daseki();
		Okiba(turnC, Fu, Sp);
		Explore(Fu, Sp);


		if (Tesuu(Fu) == 64)
			break;
	}
	Result();
	return 0;
}
