#include <iostream>

using type_sort = enum {sort_asc, sort_desc};

void swap(int *a, int *b)
{
	int t{*a};
	*a = *b;
	*b = t;
}

// сортировка по возрастанию
void sort_up(int* ar, int len)
{
	for (int i = 0; i < len; ++i)
        for (int j = i+1; j < len; ++j)
            if (ar[i] > ar[j]) {
                swap(&ar[i], &ar[j]);
            }
}

// сортировка по убыванию
void sort_down(int* ar, int len)
{
	for (int i = 0; i < len; ++i)
        for (int j = i+1; j < len; ++j)
            if (ar[i] < ar[j]) {
                swap(&ar[i], &ar[j]);
            }
}

void sort(int* ar, size_t len, type_sort type=sort_asc)
{
    switch (type) {
        case sort_asc:
            sort_up(ar, len);
            break;
        case sort_desc:
            sort_down(ar, len);
            break;
    }
}


int main(void)
{
	int len;
	std::cin >> len; std::cin.ignore();
	int ar[len];

	for (int i = 0; i < len; ++i) {
		std::cin >> ar[i]; std::cin.ignore();
	}

	sort(ar, len, sort_asc);

	for (int i = 0; i < len; ++i)
		std::cout << ar[i] << ' ';

	return 0;
}