//多种排序
//
//
//五种不同的排序方式  
//
//
#include<iostream>
#include<vector>

using namespace std;


void swap(int &a,int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}


//选择排序
//SelectionSort
//时间复杂度O(n^2)

void SelectionSort(vector<int> &v)
{
	for(int i = v.size()-1;i>0;--i){
		int max = v[i];
		int midx = i;
		for(int j= i -1;j>=0;--j){
			if(v[j] > max){
				max = v[j];
				midx = j;
			}	
		}
		swap(v[i],v[midx]);
	}
}

//插入排序  相比选择排序有最好情况 输入敏感，与逆序对数量有关
//InsertionSort
//时间复杂度为O(n^2)
void InsertionSort(vector<int> &v)
{
	for(int i=1;i<v.size();++i){
		for(int j= i;j>0;--j){
			if(v[j] < v[j-1]){
				swap(v[j-1],v[j]);	
			}
			else
				break;
		}

	}
}



//冒泡排序
//BubbleSort 有优化方法，但是意义不太大，所以这里没有优化
//时间复杂度为O(n^2)
void BubbleSort(vector<int> &v)
{
	for(int i=1;i<v.size();++i){
		for(int j=0;j<v.size() -i;++j){
			if(v[j] > v[j+1])
			       swap(v[j],v[j+1]);	
		}
	}
}




//归并排序
//MergeSort
//时间复杂度为O(nlogn)
//空间复杂度较大
//[lo,hi) = [lo,mi)+[mi,hi)
void MergeSort(vector<int> &v,int lo,int hi)
{
	if(hi - lo <2)
		return ;
	
	int mi = (hi + lo)/2;

	MergeSort(v,lo,mi);
	MergeSort(v,mi,hi);

	//2 way merge
	int i=lo,j=mi;
	vector<int> vtmp;
	while(i<mi || j <hi){

		if(i>=mi || j<hi && v[j] < v[i]){
			vtmp.push_back(v[j]);
			++j;
		}else{
			vtmp.push_back(v[i]);
			++i;
		}
	}

	for(int i=0;i<hi-lo;++i){
		v[lo+i] = vtmp[i];
	}

}




//快速排序
//QuickSort
//平均时间复杂度为0(nlogn)
//取第一个元素为pivot

void QuickSort(vector<int> &v,int lo,int hi)
{
	if(hi - lo <2)
		return ;
	
	int i=lo,j=hi-1;
	int pivot = v[lo];//第一个元素位基准点
	while(i<j){
		while( i<j && v[j] >= pivot)
			--j;
		v[i] = v[j];
		while( i<j && v[i] <= pivot )
			++i;
		v[j] = v[i];
	}//i == j
	v[i] = pivot;

	QuickSort(v,lo,i);
	QuickSort(v,i+1,hi);//i已经排序好了

}


int main(int argc,char** argv)
{

	int num;
	int tmp;
	vector<int> vec;

	cin >> num;

	for(int i=0;i<num;++i){
		
		cin >> tmp;
		vec.push_back(tmp);
	}


	//SelectionSort(vec);
	//InsertionSort(vec);
	//BubbleSort(vec);
	//MergeSort(vec,0,vec.size());
	QuickSort(vec,0,vec.size());

	for(int i=0;i<num;++i){
		cout << vec[i]<<" ";
	}
	cout << endl;



	return 0;
}





