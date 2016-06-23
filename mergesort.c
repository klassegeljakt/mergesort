#include "mergesort.h"

typedef struct data_item {
	int val;
	int id;
} data_item;

int ASCENDING(const void *a, const void *b) {
	data_item *item_a = (data_item*)a;
	data_item *item_b = (data_item*)b;
	return (item_a->val - item_b->val);
}
int merge(char *A, size_t nmemb, int (*cmp)(const void *a, const void*b),
           char *L, int left, char *R, int right) {
	int i = 0,
		j = 0,
		k = 0;
	while(i < left && j < right) {
		if(cmp(L+i*nmemb, R+j*nmemb) < 0) { /* L < R*/
			memcpy(A+k*nmemb, L+i*nmemb, nmemb);
			i++;
		}
		else { 				/* R < L */
			memcpy(A+k*nmemb, R+j*nmemb, nmemb);
			j++;
		}
		k++;
	}
 	while(i < left) {
		memcpy(A+k*nmemb, L+i*nmemb, nmemb);
		k++;
		i++;
	}
 	while(j < right) {
		memcpy(A+k*nmemb, R+j*nmemb, nmemb);
		k++;
		j++;
	}
	return 0;
}
int tdc_mergesort(void *A_void, size_t size, size_t nmemb,
				 int (*cmp)(const void *, const void *)) {
	char *A, *L, *R;
	size_t mid, i;
	if(size < 2) {
		return 0;
	}
	mid = size/2;
	A = (char*)A_void;
	L = (char*)malloc(mid * nmemb);
	R = (char*)malloc((size - mid) * nmemb);
	for(i = 0; i < mid; i++) {
		memcpy(L+i*nmemb, A+i*nmemb, nmemb);
	}
	for(i = mid; i < size; i++) {
		memcpy(R+(i-mid)*nmemb, A+i*nmemb, nmemb);
	}
	tdc_mergesort(L, mid, nmemb, cmp);
	tdc_mergesort(R, size - mid, nmemb, cmp);
	merge(A, nmemb, cmp, L, mid, R, size - mid);
	free(L);
	free(R);
}

int main(int argc, char *argv[]) {
	int i, n = 10;
	data_item *data = malloc(sizeof(data_item)*n);
	for(i = 0; i < n; i++) {
		data[i].val = n-i-1;
		data[i].id = i-1;
		fprintf(stderr, "%d ", data[i].val);
	}
	fprintf(stderr, "\n");
	tdc_mergesort(data, n,  sizeof(data_item), ASCENDING);
	for(i = 0; i < n; i++) {
		fprintf(stderr, "%d ", data[i].val);
	}
	fprintf(stderr, "\n");
	return 0;
}
/*****************************************************************************/
