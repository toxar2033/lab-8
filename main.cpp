#include <iostream>


using namespace std;



bool NOD(int x, int y){
  int r = 999, q = 0;
  while(!(x == 0)){
    int q = y / x;
    int r = y - x * q;
    y = x; x = r;
  }
  if (y == 1) return true;
  else return false;
}

int main(){

  float x, y, z = 3, t = 7;
  float tmp;

  cout << "Find the nearest fraction to 3/7\n";
  for(int i = 1000000; i > 0; --i){
    tmp = (z * i - 1)/t;
    if(tmp == (int)(tmp)){
      if(NOD(tmp,i)){
        x = tmp;
        y = i;
        break;
      }
    }
  }
  cout << "I have done at least something :)\nfraction is " << x << '/' << y << '\n';
  return 0;
}

/*Короче, мне лень будет вспомниать как это работает, поэтому запишу тут
Есть замечательная вещь под названием Дерево Штерна — Броко, которая поможет всё решить
Там получается ровно тоже самое, что и в задаче. То есть это получается дерево, в котором
хранятся несократимые дроби в порядке возрастания. Работает это так, у нас есть две рядом
стоящие несократимые дроби, мы можем найти вершину, откуда появляются эти две дроби
Даны две дроби x/y и z/t, чтобы получить вершину - родителя, мы просто находим дробь
(x+z)/(y+t). Также можно получить близжайшую дробь благодаря НОДу и формуле, следующей
из правила дерева. Возьмём те же две дроби x/y и z/t. Они будут рядомстоящими, если
xt - yz = 1. Так как нам известна одна дроб, то максимально близкая дробь слева
будет иметь наибольший знаменатель из возможных. То есть начинаем перебирать знаменатели для первой
дроби от 1000000 и ниже. Ответ найдётся достаточно быстро*/