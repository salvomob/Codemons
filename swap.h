#ifndef SWAP_H
#define SWAP_H


/*template <class T> void swapLocal(T* v, int i , int j){
	T *tmp = *v[i];
	*v[i] = *v[j];
	*v[j] = *tmp;
	std::cout << &tmp << " " <<&v[j] << "\n";
}*/

template <class T> void myswap(T* v,T *v1, int i, int j){
	T tmp = v[i];
	v[i] = v1[j];
	v1[j] = tmp;
}

#endif
