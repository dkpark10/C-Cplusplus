# Const, Friend, Static for detail

## const 객체

```c++
const Lego Batcar(324000);
```

객체도 상수화 할 수 있다. 뜻은 다음과 같다. </br>

> 이 객체의 데이터변경을 허용하지 않겠다 </br>

때문에 const멤버함수의 호출만 허용가능하다. </br>
애초에 데이터변경함수가 아니더라도 const를 쓰게함으로서 </br>
싹을 잘라버린다. </br>

![캡처](https://user-images.githubusercontent.com/43857226/69402805-4d0b3380-0d3c-11ea-9537-c77a28b85dc1.PNG) </br>

const 함수의 호출만 가능하다. 

## const와 함수 오버로딩 

함수의 오버로딩 성립기준은 인자의 개수나 자료형의 변화이다. </br>
다음과 같이 const 여부도 함수오버로딩이 가능하다. </br>

```c++
int GetPower() {...}
int GetPower()const {...}
```

![캡처](https://user-images.githubusercontent.com/43857226/69403309-93ad5d80-0d3d-11ea-9a65-43236507908a.PNG) </br>

출력 결과는 다음과 같다.</br>

> not const !!!! </br>
const !!!! </br>

데이터 자료형과 파라미터개수가 동일하지만(사실 없지만..) const 여부로</br>
함수오버로딩이 되는것을 볼 수 있다. </br>
다음 코드도 봐보자 !!!! </br>

![캡처](https://user-images.githubusercontent.com/43857226/69403527-251ccf80-0d3e-11ea-9aa9-82d42c794ce6.PNG) </br>

신한은행은 const 객체가 아니지만 다음 Test함수에 들어가면</br>
**const참조자** 로 받아서 const객체가 되고 const멤버함수가 호출된다. </br>
이로서 const함수가 언제 호출되는지 알아볼 수 있었다 지식이 늘어따 </br>

## Friend는 친구

friend선언은 private멤버 접근을 허용하는 선언이다. </br>
private는 정보 은닉성 때문에 아무나 들어갈 수 없다. 다음을 보자 </br>

![캡처](https://user-images.githubusercontent.com/43857226/69404146-db34e900-0d3f-11ea-8f5b-491be8d6c56b.PNG) </br>

남자친구 클래스 멤버변수의 여자친구 객체가 있다. </br>
이는 여자친구 객체는 남자친구 객체의 멤버변수의 직접접근이 가능하다. </br>
**참고로 friend선언은 클래스 내부 어디에 써도 상관없다.**

![캡처](https://user-images.githubusercontent.com/43857226/69404281-41ba0700-0d40-11ea-8c2d-d1bff9defbea.PNG) </br>

출력결과는 남자친구 객체의 머니변수를 리턴한다. </br>
ShowBoyMoney함수를 보자 남자친구 객체를 인자로 받아 </br>
남자친구 객체의 멤버변수의 직접접근이 가능한것을 볼 수 있다. </br>
