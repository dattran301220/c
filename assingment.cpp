#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void reverseWords(string sentence) {
    stringstream ss(sentence);
    string word;
    bool first = true;

    while (ss >> word) {
        reverse(word.begin(), word.end());
        if (!first) cout << " ";
        cout << word;
        first = false;
    } 
    cout << endl;
}

int uoc (int a,int b){
	while (b!=0){
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
void sapxep(int a[], int n) {
    sort(a, a + n);  
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";  
    }
    cout << endl;
}
void tong(int a[], int n) {
    sort(a, a + n);
	int s=a[0]+a[n-1]; 
	cout<<s;  
}
int main (){
   int a,b;
   cin>>a>>b;
   cout<<uoc(a,b);
   int arr[100];
   int n;
   cin>>n;
   for (int i=0;i<n;i++){
   	cin>>arr[i];
   	
   }
   sapxep(arr,n);
   tong (arr,n);
}

