#ifndef CGEN_H
#define CGEN_H

void Cgen(const int n, const int r, int select, int *array, int *index)
{
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			select |= (1 << i);
			array[*index] = select;
			(*index)++;
			select &= ~(1 << i);
		}
		return;
	}
	for (int a = r - 1; a < n; a++) {
		select |= (1 << a);
		Cgen(a, r - 1, select, array, index);
		select &= ~(1 << a);
	}
}

#endif
