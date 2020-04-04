########################
---gentic algorithm----------


#include<bits/stdc++.h>
using namespace std;
#define size 100
#define stsize 50
struct indi{
	vector<int> chr;
	double fit;
};
int marks[stsize]={0};
void initialise(int *marks){
	for(int i=0;i<stsize;i++){
		marks[i] = 20+(rand()%80);
	}
}
bool compare(indi ind1,indi ind2){
	return ind1.fit<ind2.fit;
}
void assign_grp(indi &ind){
	//cout<<"f1"<<endl;
	vector<int> c(stsize);
	for(int i=0;i<stsize;i++){
	//	cout<<"f1 start"<<endl;
		c[i] = (rand()%3);
	//	cout<<"f1 bet"<<endl;
	}
	ind.chr=c;
	//cout<<"f1 end"<<endl;
	return;
}
double variance(indi &ind,int i){
	int sum=0,n=0;
	double sqdiff=0;
	for(int j=0;j<stsize;j++){
		if(ind.chr[j]==i){
			sum+=marks[j];
			n++;
		} 
	}
	double mean=((double)sum/(double)n);
	for(int j=0;j<stsize;j++){
		if(ind.chr[j]==i) {
			sqdiff+=((marks[j]-mean)*(marks[j]-mean));
		} 
	}
	return sqdiff/(double)n;
}
double diversity(indi &ind,int i){
	return sqrt(variance(ind,i));
}
double calc_fit(indi &ind){
	double div[3]={0};
	for(int i=0;i<3;i++){
		div[i]=diversity(ind,i);
	}
	ind.fit = (div[0]+div[1]+div[2])/3; 
}
indi mate(indi &p1,indi &p2){
	vector<int> cc(stsize);
	indi chromosome;
	for(int i=0;i<stsize;i++){
		double p=(rand()%101)/(double)100;
		if(p<0.4){
			cc[i]=p1.chr[i];
		}
		else{
			if(p<0.8){
				cc[i]=p2.chr[i];
			}
			else cc[i]=(rand()%3);
		}
	}
	chromosome.chr=cc;
	//cout<<"bye"<<endl;
	return chromosome;
}
int main(){
	srand(time(0));
	int n=100,g=1,it=300;
	initialise(marks);
	vector<indi>pop;
	for(int i=0;i<size;i++){
		indi c;
		assign_grp(c);
		c.fit=calc_fit(c);
		pop.push_back(c);
		cout<<endl;
	}
	while(it--){
			sort(pop.begin(),pop.end(),compare);
			cout<<"generation "<<g<<" fitness:"<<pop[0].fit<<endl;
			g++;
			vector<indi> newgen(stsize);
			int s=(10*size)/100;
			int n=0;
			for(int i=0;i<s;i++){
				indi t=pop[i];
				newgen[i]=t;
				n++;
			}
			for(int i=n;i<stsize;i++){
				int r1=(rand()%(size/2));
				indi p1=pop[r1];
				r1=(size/2)+(rand()%(size/2));
				indi p2=pop[r1];
				indi c1=mate(p1,p2);
				calc_fit(c1);
				newgen[i]=c1;
			}
			pop=newgen;
		}
		cout<<"In last generation the grouping is as follows:"<<endl;
		vector<vector<int> >v(3);
		for(int i=0;i<stsize;i++){
			int a=pop[0].chr[i];
			if(a==0) v[0].push_back(marks[i]);
			else {
				if(a==1) v[1].push_back(marks[i]);
				else v[2].push_back(marks[i]);
			}
		}
		for(int i=0;i<3;i++){
			for(typeof(v[i].begin()) j=v[i].begin();j!=v[i].end();j++){
				cout<<*j<<" ";
			}
			cout<<endl;
		}
		cout<<"maximum fitness is:"<<pop[0].fit<<endl;
		return 0;
}
