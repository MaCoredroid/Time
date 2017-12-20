#include <iostream>

using namespace std;

class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int a=0,int b=0,int c=0):hour(a),minute(b),second(c)
{

}
void deal(Time &a)
{
   if(a.second>=60)
  {
      a.second-=60;
      a.minute++;
  }
  if(a.second<0)
  {
      a.second+=60;
      a.minute--;
  }
  if(a.minute>=60)
  {
      a.minute-=60;
      a.hour++;
  }
  if(a.minute<0)
  {
      a.minute+=60;
      a.hour--;
  }
  if(a.hour>=24)
  {
      a.hour-=24;
  }
  if(a.hour<0)
  {
      a.hour+=24;
  }
}
Time &operator+=(const Time&a)
{
  hour+=a.hour;
  minute+=a.minute;
  second+=a.second;
  deal(*this);
  return *this;
}
Time &operator-=(const Time&a)
{
   hour-=a.hour;
  minute-=a.minute;
  second-=a.second;
  deal(*this);
  return *this;
}
Time& operator++()
{
    second++;
    deal(*this);
    return *this;

}
Time operator++(int n)
{
    Time tmp=*this;
    second++;
    deal(*this);
    return tmp;
}
Time& operator--()
{
    second--;
    deal(*this);
    return *this;

}
Time operator--(int n)
{
    Time tmp=*this;
    second--;
    deal(*this);
    return tmp;
}

void display()
{
    if(hour<=9)
        cout<<'0'<<hour<<':';
    else
        cout<<hour<<':';
    if(minute<=9)
        cout<<'0'<<minute<<':';
    else
        cout<<minute<<':';
    if(second<=9)
        cout<<'0'<<second;
    else
        cout<<second;
}

};

int main()
{
  int h1,m1,s1,h2,m2,s2;
  cin>>h1>>m1>>s1;
  Time time1(h1,m1,s1);
  cin>>h2>>m2>>s2;
  Time time2(h2,m2,s2);

  time1 += (time2++);
  time1.display();
  cout<<endl;

  time1 -= time2;
  time1.display();
  cout<<endl;

  ++time2;
  time2.display();
  cout<<endl;

  time2 += (time1--);
  time2.display();
  cout<<endl;

  --time1;
  time1.display();
  cout<<endl;

  time2 -= time1;
  time2.display();
  return 0;

}
