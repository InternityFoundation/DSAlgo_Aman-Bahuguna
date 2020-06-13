template <typename T>
class convert
{
private :
    T n;

public :

    convert(T n)
    {
        this->n = n;
    }

    int convertBinarytoOctal(long long binaryNumber)
    {
    int octalNumber = 0, decimalNumber = 0, i = 0;

    while(binaryNumber != 0)
    {
        decimalNumber += (binaryNumber%10) * pow(2,i);
        ++i;
        binaryNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}

long long convertOctalToBinary(int octalNumber)
{
    int decimalNumber = 0, i = 0;
    long long binaryNumber = 0;

    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }

    return binaryNumber;
}

    int Decimal_T0_Octal(int n) {
        int r, i = 1, ans = 0;
        while(n > 0) {
            r = n % 8;
            ans += (r * i);
            n = n / 8;
            i *= 10;
       }
       return ans;
    }

    int Octal_TO_Decimal(int n) {
        int d, i = 0, ans = 0;;
        while (n > 0) {
            d = n % 10;
            ans += (d * pow(8, i));
            n = n / 10;
            i++;
        }
        return ans;
    }

    void decToHexa(int n)  {
        char hexaDeciNum[100];
        int i = 0;
        while(n!=0)  {
            int temp  = 0;
            temp = n % 16;
            if(temp < 10) {
               hexaDeciNum[i] = temp + 48;
               i++;
            }
            else {
               hexaDeciNum[i] = temp + 55;
               i++;
            }
            n = n/16;
        }
        for(int j=i-1; j>=0; j--)
        cout << hexaDeciNum[j];
      }

      int hexadecimalToDecimal(char hexVal[]) {
          int len = strlen(hexVal);
          int base = 1;
          int dec_val = 0;
          for (int i=len-1; i>=0; i--) {
              if (hexVal[i]>='0' && hexVal[i]<='9'){
                  dec_val += (hexVal[i] - 48)*base;
                  base = base * 16;
              }
              else if (hexVal[i]>='A' && hexVal[i]<='F') {
                  dec_val += (hexVal[i] - 55)*base;
                  base = base*16;
              }
           }
           return dec_val;
       }

       string hex_to_bin(string s)
       {
           int n=s.length();
           string st="";
           unordered_map<char, string> um;
           um['0'] = "0000";
           um['1'] = "0001";
           um['2'] ="0010" ;
           um['3'] = "0011";
           um['4'] = "0100";
           um['5'] = "0101";
           um['6'] = "0110";
           um['7'] = "0111";
           um['8'] = "1000";
           um['9'] = "1001";
           um['A'] = "1010";
           um['B'] = "1011";
           um['C'] = "1100";
           um['D'] = "1101";
           um['E'] = "1110";
           um['F'] = "1111";

           for(int i=0;i<n;i++)
           {
                char a=s[i];
                st+=um[a];
           }
           return st;
       }

       void bin_to_hex(string s)
{
  int n=s.length();
 string st="";
  unordered_map<string, char> um;
    um["0000"] = '0';
    um["0001"] = '1';
    um["0010"] = '2';
    um["0011"] = '3';
    um["0100"] = '4';
    um["0101"] = '5';
    um["0110"] = '6';
    um["0111"] = '7';
    um["1000"] = '8';
    um["1001"] = '9';
    um["1010"] = 'A';
    um["1011"] = 'B';
    um["1100"] = 'C';
    um["1101"] = 'D';
    um["1110"] = 'E';
    um["1111"] = 'F';


  for (int i = 1; i <= (4 - n % 4) % 4; i++)
            s = '0' + s;

n=s.length();
int c;
  for( int i=0; i<n; i++)
{
    if((s[i]!= '1') && (s[i]!= '0'))
    {
    cout<<"Invalid input";
    break;
    }
    else
    c=1;
}
if(c==1)

  {for(int i=0;i<n;i=i+4)
{
    string a=s.substr(i,4);
    //cout<<a<<endl;
    st+=um[a];
}cout<<st<<endl;}

}

void dec_to_bin(int n)
{
int binaryNum[32];
int i = 0;
while (n > 0) {
binaryNum[i] = n % 2;
n = n / 2;
i++;
}
for (int j = i - 1; j >= 0; j--) {
    cout << binaryNum[j];
}
}

int real(string n)
{ int original=stoi(n);
 int temp=original;
int dec=0;
int base=1;

while(temp)
{int a=temp%10;
temp=temp/10;
dec=dec+a*base;
base=base*2;}
return dec;
}

void Bin_to_dec(string n)
{string original=n;
//cout<<original<<endl;
string temp=n;
 int c;
 int length=temp.length();
//cout<<length<<endl;
for( int i=0; i<length; i++)
{
    if((temp[i]!= '1') && (temp[i]!= '0'))
    {
    cout<<"Invalid input";
    break;
    }
    else
    c=1;
}
if(c==1)
cout<<real(original);
}

};
