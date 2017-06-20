#include <iostream>
#include <string>
using namespace std;
/*
 P为模式串，下标从0开始
*/
void GetNext(string P, int next[]) {
	int p_len = P.size();
	int i = 0; //下标
	int j = -1;
	next[0] = -1;
	
	while (i < p_len) {
		if (j == -1 || P[i] == P[j]) {
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

/*
 优化：P为模式串，下标从0开始
*/
void GetNext(string P, int next[]) {
	int p_len = P.size();
	int i = 0; //下标
	int j = -1;
	nextval[0] = -1;
	
	while (i < p_len) {
		if (j == -1 || P[i] == P[j]) {
			i++;
			j++;
			if (P[i] == P[j]) {
				/* 如果与前缀字符相同，则将前缀 */
				/* 字符的nextval值赋值给nextval在i位置的值 */
				nextval[i] = nextval[j];
			} else {
				/*则当前的j为nextval在i位置的值*/
				nextval[i] = j;
			}
		} else {
			j = nextval[j];
		}
	}
}

/* 在S中找到P第一次出现的位置  */
int KMP(string S, string P, int next[]) {
	GetNext(P, next);	
	
	int i = 0;
	int j = 0;
	int s_len = S.size();
	int p_len = P.size();
	
	while (i < s_len && j < p_len) {
		if (j == -1 || S[i] == P[j]) {//P的第一个字符不匹配或S[i] == P[j]
			i++;
			j++;
		} else {
			j = next[j]; //当前字符匹配失败,跳转
		}
	}
	if (j == p_len) {
		return i - j;
	}
	
	return -1;
}


int main(int argc, char *argv[]) {
	
	int next[100] = {0};
	cout << KMP("bbc abcdab abcdabcdabde", "abcdabd", next) << endl;
	return 0;
}