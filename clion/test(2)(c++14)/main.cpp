
#include <iostream>
#include <numeric>
#include <vector>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <queue>
#include <stack>
#include <list>
using namespace  std;
using namespace std::placeholders;

//用迭代器正向和反向遍历vector数组
template<class T>
void print_forward_vector_domo (const vector<T>v ){
    typename vector<T>::const_iterator it =v.begin();
    for(it;it!=v.end();it++){
        cout<<*it<<ends;
    }
    cout<<endl;
}
template<class T>
void print_forward_vector (const vector<T>v ){
    auto it =v.begin();
    for(it;it!=v.end();it++){
        cout<<*it<<ends;
    }
    cout<<endl;
}
template<class T>
void print_backward_vector (const vector<T>v ){
    auto it =v.end();
    for(it;it!=v.begin();it--){
        cout<<*it<<ends;
    }
    cout<<endl;
}
//回调函数(没有必要)
template<class T>
void print_vector_int (vector<T>(*Function_pointer)(vector<T>),vector<T>v){
    (*Function_pointer)(v);
}

//用迭代器正向和反向遍历map
template<class T1,class T2>
void print_forward_map (const map<T1,T2>m){
    auto it = m.begin();
    for(;it!=m.end();it++){
        cout<<it->first<<ends<<it->second<<endl;
    }
}
template<class T1,class T2>
void print_backward_map (const map<T1,T2>m){
    auto it = m.begin();
    for(;it!=m.begin();it--){
        cout<<it->first<<ends<<it->second<<endl;
    }
}

//计时函数


//函数指针练习
//int max(int a,int b){
//    return a>b?a:b;
//}
//int min(int a,int b){
//    return a<b?a:b;
//}
//int (*p1_max)(int a,int b)=max;
//int (*p2_min)(int a,int b)=min;
//void Print(int (*p)(int,int),int a,int b){
//    cout<<(*p)(a,b)<<endl;
//}


//高精度减法
//void print(const vector<int>& x){
//    for( vector<int>::const_iterator it1=x.begin();it1!=x.end();it1++){
//        cout<<*it1;
//    }
//    cout<<endl;
//}
//void translate(const string x,vector<int>& y){
//    for(int i=x.size();i>=0;i--) {
//        y[i] = x[i] - '0';
//    }
//    print(y);
//}
class Example {
public:
    string minuend_str;
    string subtractor_str;
    vector<int> minuend;
    vector<int> subtractor;
    vector<int> answer;


//构造函数
//    Example(string s1,string s2):minuend_str(s1),subtractor_str(s2),minuend(minuend_str.size()>subtractor_str.size()?minuend_str.size():subtractor_str.size(),0),subtractor(minuend_str.size()>subtractor_str.size()?minuend_str.size():subtractor_str.size(),0),answer(minuend_str.size()>subtractor_str.size()?minuend_str.size():subtractor_str.size(),0){}

//构造函数
      Example(string str1="0000",string str2="0000"):minuend_str(str1),subtractor_str(str2){}

//    void set(){
//        cout<<"输入被减数"<<endl;
//        cin >> minuend_str;
//        cout<<"输入减数"<<endl;
//        cin >> subtractor_str;
//        translate(minuend_str,minuend);
//        translate(subtractor_str,subtractor);
//    }
        ~Example()
        {
            minuend_str.erase();
            subtractor_str.erase();
            minuend.clear();
            subtractor.clear();
            cout<<"Example释放"<<endl;
        }
//        void subtract() {
//            if(minuend_str[0]>=subtractor_str[0]){
//              for(int i=minuend_str.size();i>=0;i--) {
//                 if (minuend_str[i]>=subtractor_str[i]){
//                     answer[i]=minuend_str[i]-subtractor_str[i];
//                 }else{
//                     answer[i]=minuend_str[i]+10-subtractor_str[i];
//                     minuend_str[i-1]-=1;
//                 }
//              }
//                print(answer);
//
//            }else{
//
//            }
 //       }
    };
//删除器，函数
void Delete_Example_function (Example* p){
    delete p;
    cout<<"Delete_Example_function被调用"<<endl;
}
//删除器，仿函数
class Delete_Example_likeFuntion{
public:
    void operator() (Example * p){
        delete p;
        cout<<"Delete_Example_likeFuntion被调用"<<endl;
    }
};
//删除器，lembda
auto lembda_delete_Example =[](Example* p){
    delete p;
    cout<<"lembda_delete_Example被调用"<<endl;
};

//回调函数练习
class Test;
typedef int  (*pointer)(int,int);
class Test{
public:
    static int Max (int a,int b){
        return a>b?a:b;
    }
    void receiver(pointer p,int a,int b){
        cout<<(*p)(a,b)<<endl;
    }

};



//bind函数练习
//int square(int x,int n){
//    int sum;
//    if(x!=0) {
//            sum = 1;
//        for (int i = 0; i < n; i++) {
//            sum *= x;
//        }
//    }else{
//        sum=0;
//    }
//return sum;
//}
//auto square_2= bind(square,_1,2);
//bool check_size(const string &s,string::size_type sz){
//    return s.size()>=sz;
//}
//void sw(int& a,int& b){
//    int x;
//    x=b;b=a;a=x;
//}
//auto sw_2= bind(sw,_1,1314);
//class Example{
//public:
//    static int data_1;
//    static int add_1(int a,int b){
//        return  a+b;
//    }
//    int date_2;
//    int add_2(int a,int b){
//        return a+b;
//    }
//};
//int Example::data_1=999;
//Example ex;
//auto bind_date_2= bind(&Example::date_2,&ex);


    int main() {
        //高精度减法
//        Example ex("987654321","123456789");
//        translate(ex.minuend_str,ex.minuend);
//        translate(ex.subtractor_str,ex.subtractor);
//        ex.subtract();

      //vector练习
//      string str1("aaaadddd");vector<int>v1;
//      int ar1[]={1,2,3,4,5};
//      cout<<v1.empty()<<endl;
//      v1.resize(10);
//      cout<<v1.size()<<endl;
//      cout<<v1.capacity()<<endl;
//      print(v1);
//      v1.resize(20,9);
//      print(v1);
//    v1.push_back(5);
//        print(v1);
//      vector<int>::iterator it1=v1.begin();
//        v1.insert(it1,-1);
//        cout<<*v1.begin()<<endl;
//        v1.insert(it1,6,6);
//        print(v1);


//        vector<int> v1 = {0, 1, 2, 3, 4, 5};
//        auto m = [&] {return v1.begin() + v1.size() / 2;};
//        vector<int>::iterator vb = v1.begin();
//        vector<int>::iterator vm = v1.begin() + v1.size() / 2;
//        v1.insert(vb, -1);
//        cout << "vb = " << *vb << endl;
//        cout << "vm = " << *vm << endl;
//        cout << "vb's position:" << vb - v1.begin() << endl;
//        cout << "vm's position:" << vm - v1.begin() << endl;
//        cout << "v1 = " << *v1.begin() << endl;



//string容器练习
//      string str1("1a2b3c4d5e6f6f5e4d3c2b1a");
//      string str2(str1);
//      string str3(&str1[0],&str1[5]);
////      cout<<str1.find("1a",0)<<endl;
////      cout<<str1<<endl;
////      cout<<str1.c_str()<<endl;
////      cout<<str1.find("1",0,5)<<endl;
////      cout<<str1.find("3c2",0,2)<<endl;
//
////对组及set、map
//pair<char,string>pair_example1('b',"bbb");
//pair<char,char>pair_example2('a','a');
//map<char,string>m1;
//m1.insert(pair_example1);
//m1.insert(pair<char,string>('a',"aaa"));
//map<char,string>m2(m1);
////m2['b']="ccc";
////        print_forward_map(m1);
////cout<<m1.lower_bound('b')->second<<endl;
////cout<<m1.upper_bound('a')->second<<endl;
//set<char> set1(str1.begin(),str1.end());
//
//
//
////智能指针
//shared_ptr<Example[]> sp1_Example_array (new Example[2]);
//shared_ptr<Example> sp2_Example ( new Example(), Delete_Example_likeFuntion());
//shared_ptr<Example> sp3_Example ( new Example(), lembda_delete_Example);
//shared_ptr<Example> sp4_Example = make_shared<Example>();
//
//shared_ptr<Example[]> sp5_Example_array (new Example[1]{{}});
//Example ex1("1111","1111");
//
////queue、stack练习
//int ar[]={1,2,3,4,5};
//deque<int> deque1(&ar[0],&ar[5]);
//deque<int> deque2 ={1,2,3,4,5};
//queue<int> queue1;
//
//
////list
//list<char> list1 ={'a','b','c',};
//list<char>::iterator list_it1 =list1.begin();

        int * ptr1 =new int[5];
       cout<<sizeof(ptr1)<<endl;
        cout<<sizeof(int)<<endl;



//回调函数练习
    Test t;
    t.receiver(&Test::Max,5,6);














        return 0;
    }

//函数指针练习
//    Print(p1_max,4,5);
//    Print(p2_min,4,5);




        //lembda练习
//   int a=0;
//   auto f1=[&a]() {return a+9;};
//    auto f2=[a]() {return a+9;};
//    auto f=[](){return "lembda";};
//    cout<<f1() <<endl;
//    cout<<f2() <<endl;
//    cout<<f()<<endl;
//    a++;
//    cout<<f1() <<endl;
//    cout<<f2() <<endl;
        //cout<<[](){return 20;}<<endl;



        //bind函数练习
//        auto fun = [](int *array, int n, int num){
//            for (int i = 0; i < n; i++)
//            {
//                if (array[i] > num)
//                    cout << array[i] << ends;
//            }
//            cout << endl;
//        };
//        int array[] = { 1, 3, 5, 7, 9 };
//        //_1，_2 是占位符
//        auto fun1 = bind(fun,_1, _2, 5);
//        //等价于调用fun(array, sizeof(array) / sizeof(*array), 5);
//        fun1(array, sizeof(array) / sizeof(*array));
//        cin.get();





        //vector容器练习
//   int a=9;
//   vector<int>v1(5,a);
//   vector<int>v2(v1);
//   vector<int>v3(v1.begin(),v1.end());
//   vector<int>::iterator it1 =v1.begin();
//   vector<int>::iterator it2 =v1.end();
//   vector<int>v4(it1,it2);
//
//   auto print1=[&](const vector<int>& v)mutable {
//       for(int i=0;i<v.size();i++){
//           cout<<v[i]<<" ";
//       }
//       cout<<endl;
//   };
//   print1(v3);
//
//   auto print2=[&]( const vector<int>v)mutable {
//   vector<int>::const_iterator v_it1 =v.begin();
//   vector<int>::const_iterator v_it2 =v.end();
//       for(v_it1=v_it1+2;v_it1<v_it2-1;v_it1++){
//        cout<<*it1<<" ";
//    }
//       cout<<endl;
//};
//   print2(v3);

//    vector<int> v;
//    for (int i = 0; i < 100000;i ++){
//        v.push_back(i);
//    }
//
//    cout << "capacity:" << v.capacity() << endl;
//    cout << "size:" << v.size() << endl;
//
//    //此时 通过resize改变容器大小
//    v.resize(10);
//
//    cout << "capacity:" << v.capacity() << endl;
//    cout << "size:" << v.size() << endl;
//
//    //容量没有改变
//    vector<int>(v).swap(v);
//
//    cout << "capacity:" << v.capacity() << endl;
//    cout << "size:" << v.size() << endl;









