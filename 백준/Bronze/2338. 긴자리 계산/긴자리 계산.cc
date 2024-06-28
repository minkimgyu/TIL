#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct BigNumber {
    struct numberString{
        bool isMinus;
        string absString, rev;
        int len;
        numberString(string x) {
            if(x[0]=='-') {
                isMinus=true;
                absString=x.substr(1);
                len=absString.length();
            } else {
                isMinus=false;
                absString=x;
                len=absString.length();
            }
            rev=absString;
            reverse(begin(rev), end(rev));
        }
    };

    numberString op1, op2;
    bool swapped=false;

    BigNumber(string a, string b): op1(a), op2(b) {
        if(op1.len < op2.len || 
        (op1.len==op2.len && op1.absString < op2.absString)) {
            swap(op1, op2);
            swapped=true;
        }
    }

    string add(string sa, string sb){
        string ans="";
        if(sa.length()<sb.length()) 
            swap(sa,sb);

        int alen=sa.length(), blen=sb.length();
        for(int i=blen;i<alen;i++) 
            sb+='0';

        int carry=0;
        for(int i=0;i<alen;i++){
            int x=sa[i]-'0', y=sb[i]-'0';
            int s=x+y+carry;
            carry=s/10;
            s%=10;
            ans+=s+'0';
        }

        if(carry) ans+='1';
        return ans; 
    }

    void removeLeading0(string &str){
        int len=str.length();
        int pos=0;
        for(;pos<len;pos++) 
            if(str[pos]!='0') break;

        if(pos==len) str="0";
        else str=str.substr(pos);
    }

    string add(){
        string ans="";

        if(op1.isMinus==op2.isMinus){
            ans=add(op1.rev, op2.rev);
            reverse(ans.begin(),ans.end());
            removeLeading0(ans);
            if(op1.isMinus==true && ans!="0") 
                ans='-'+ans;
            return ans;
        }

        string nine_complement="";
        for(int i=0;i<op1.len;i++) 
            nine_complement+='0'+('9'-op1.rev[i]);
        string tmp=add(nine_complement, op2.rev);    

        for(int i=0;i<op1.len;i++) 
            ans+='0'+('9'-tmp[i]);
        reverse(ans.begin(), ans.end());   
        removeLeading0(ans);
        
        if(ans=="0") return ans;

        if(op1.isMinus==true)
            ans='-'+ans;
        return ans;
    }

    string sub(){
        bool b=op2.isMinus;
        op2.isMinus=!op2.isMinus;
        string ans=add();
        op2.isMinus=!op2.isMinus;

        if(ans=="0") return ans;
        if(swapped==true){
            if(ans[0]=='-') return ans.substr(1);
            else return '-'+ans;
        }
        return ans;
    }

    string mul(string x,int y){
        string ans="";
        int carry=0;

        for(int i=0;i<x.length();i++) {
            int tmp=(x[i]-'0')*y+carry;
            ans+='0'+(tmp%10);
            carry=tmp/10;
        }
        if(carry) ans+='0'+carry;
        
        return ans;
    }

    string mul(){
        string ans="";
        for(int i=0;i<op2.len;i++){
            if(op2.rev[i]=='0') continue;
            string zeros="";
            for(int j=0;j<i;j++) 
                zeros+='0';
            string tmp=mul(op1.rev, op2.rev[i]-'0');
            tmp=zeros+tmp;
            ans=add(tmp, ans);
        }

        reverse(ans.begin(), ans.end());
        if(op1.isMinus!=op2.isMinus) ans='-'+ans;
        return ans;
    }
};

int main(){
    string a,b;
    cin >> a >> b;

    if(b=="0") {
        cout << a << "\n";
        cout << a << "\n";
        cout << "0\n";
        return 0;
    }

    if(a=="0"){
        cout << b << "\n";
        cout << (b[0]=='-'?b.substr(1):'-'+b) << "\n";
        cout << "0\n";
        return 0;
    }

    BigNumber bn(a,b);
    cout << bn.add() << "\n";
    cout << bn.sub() << "\n";
    cout << bn.mul() << "\n";
}