#include <stdio.h>
#define SIZE 50

struct mat {
		int row;
		int col;
		int value[SIZE][SIZE];
};

void scan_mat(struct mat *);

void print_mat(const struct mat *);

void add_mat(const struct mat *m1, const struct mat *m2, struct mat *result)
{
		result->row = m1->row;
		result->col = m1->col;
		for (int i = 0; i < result->row; i++)
				for (int j = 0; j < result->col; j++)
						result->value[i][j] = m1->value[i][j] + m2->value[i][j];
}

void mul_mat(const struct mat *m1, const struct mat *m2, struct mat *result)
{
		result->row = m1->row;
		result->col = m2->col;
		for (int i = 0; i < result->row; i++) {
				for (int j = 0; j < result->col; j++) {
						result->value[i][j] = 0;
						for (int k = 0; k < m1->col; k++)
								result->value[i][j] += (m1->value[i][k] * m2->value[k][j]);
				}
		}
}

int main(void)
{
		struct mat m1, m2, result;
		char op;
		scan_mat(&m1);
		scanf(" %c", &op);
		scan_mat(&m2);
		switch (op) {
		case '+':
				add_mat(&m1, &m2, &result);
				break;
		case '*':
				mul_mat(&m1, &m2, &result);
				break;
		}
		print_mat(&result);
		return 0;
}

void scan_mat(struct mat *m_p)
{
		scanf("%d %d", &m_p->row, &m_p->col);
		for (int i = 0; i < m_p->row; ++i)
				for (int j = 0; j < m_p->col; ++j)
						scanf("%d", &m_p->value[i][j]);
}

void print_mat(const struct mat *m_p)
{
		for (int i = 0; i < m_p->row; ++i) {
				for (int j = 0; j < m_p->col; ++j) {
						printf("%d ", m_p->value[i][j]);
						if (j == m_p->col - 1)
								printf("\n");
				}
		}
}
