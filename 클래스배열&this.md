# 클래스배열 & this 포인터

클래스도 배열처럼 선언 쌉가능 </br>

![캡처](https://user-images.githubusercontent.com/43857226/68920021-508c4100-07b7-11ea-8a1e-f4a2c960b228.PNG)</br>

배열을 선언하기위해 생성자의 매개변수를 제외했다. </br>
생성자의 매개변수가 있으면 일일이 인자로 전달해야하기 때문 </br>
이렇게 선언하면 된당. 출력결과는 다음과 같다.</br>

> 0 - hazard</br>
1 - benzema</br>
2 - bale</br>
called des</br>
called des</br>
called des</br>

![캡처](https://user-images.githubusercontent.com/43857226/68920420-84b43180-07b8-11ea-8c81-9c49719b0852.PNG) </br>
다음은 포인터로 힙할당 방식이다. </br>
별거 없다 똑같다 걍 출력결과는 위와 동일</br> 

# this포인터
this는 객체 자기 자신이다. 파이썬의 self와 용도가 똑같다. </br>
아래 코드를 보자 </br>

![캡처](https://user-images.githubusercontent.com/43857226/68920974-76671500-07ba-11ea-843e-8d9e100bf3ba.PNG)</br>

다음 빨간 박스를 보자 </br>
첫번째 빨간박스는 객체 자기 자신의 포인터를 반환하는 함수이다. </br>
this가 반환된다. this는 자기 자신 객체를 가리키는 포인터 !! </br>
그래서 출력해보면 &Person과 this랑 똑같은 주소임을 확인할 수 있다. </br>
그래서 다음과 같이 멤버변수와 똑같은 변수명을 정의할 때 이렇게 쓸 수 있다. </br>

```c++
Person(int age)
  this->age = age;
```
this는 자기 자신이므로 -> 연산자를 통해 자기 자신의 멤버변수를
가리킬 수 있다. </br>


