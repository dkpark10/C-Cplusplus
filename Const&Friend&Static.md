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
friend class Girl에서 class는 girl이 클래스임을 알려주는 것이다. </br> 
**참고로 friend선언은 클래스 내부 어디에 써도 상관없다.** </br>

![캡처](https://user-images.githubusercontent.com/43857226/69404281-41ba0700-0d40-11ea-8c2d-d1bff9defbea.PNG) </br>

출력결과는 남자친구 객체의 머니변수를 리턴한다. </br>
ShowBoyMoney함수를 보자 남자친구 객체를 인자로 받아 </br>
남자친구 객체의 멤버변수의 직접접근이 가능한것을 볼 수 있다. </br>
**참고로 friend 선언은 함부로 하지말자...** </br>
이유는 정보은닉을 쉽게 깨트리기 때문! </br>

## static !!!!!!!!!!!!!

씨쁠쁠에서 멤버변수와 멤버함수의 static선언 쌉가능 static개념 다시한번 짚자</br>
전역변수 static </br>
> 선언된 파일 내에서만 참조가능 </br>
함수내 static </br>
한번만 초기화되고 함수를 빠져나가도 그대로 살아있음 </br>

![캡처](https://user-images.githubusercontent.com/43857226/69406215-e76f7500-0d44-11ea-9a8f-02cae193ca0b.PNG) </br>

위 코드는 기업이 생성되고 고객수가 증가하는 간단한 프로그램이다. </br>
하지만 위 전역변수에 접근하는 제한은 아무것도 없기 때문에 어디에서 누구라도 </br>
접근가능한 아주 위험성이 다분한 코드이다. 다음과 같이 짜서 안전하게 해주자.</br> 

![캡처](https://user-images.githubusercontent.com/43857226/69407217-5948be00-0d47-11ea-97ca-c2c4ac6d31bb.PNG) </br> 

클래스 내 멤버변수를 static으로 선언 클래스 외부에 전역으로 선언해준다. </br>
클래스 외부에 선언하는 이유는 내부에서 초기화하면 생성될 때 마다 초기화되니까(당연한거다) </br>
위 선언된 static 변수는 개체가 생성될 때마다 생성되는 변수가 아님 </br> 
객체를 생성하건 하지않건 메모리공간에 딱 하나만 할당이 되어 공유되는 변수 </br> 
다음 그림과 같다. </br> 

![제목 없음](https://user-images.githubusercontent.com/43857226/69407617-4be00380-0d48-11ea-8e6d-3caed6cd08b9.png) </br>

**그렇다고 이 static변수는 클래스내 멤버변수로 오해하면 절대 안된다.** </br>
static변수를 public으로 선언하면 어떨까 ... </br>

![캡처](https://user-images.githubusercontent.com/43857226/69408761-eccfbe00-0d4a-11ea-9e68-eea207e8011f.PNG) </br>

머 어쩌기는 위코드처럼 누구나 다 접근가능하다. </br>
특히 메인함수 맨 첫줄 객체를 생성하지 않았는데도 저렇게 접근이 가능하다. </br>

### static 멤버함수에 대해...

static멤버함수 역시 변수와 동일하다 </br>

> 선언된 클래스의 모든 객체가 공유한다. </br>
public으로 선언되면 클래스이름을 이용해 호출 쌉가능 </br>
객체의 멤버가 아니다 </br>

여기서 중요한점은 static함수는 객체의 멤버가 아니라는 점이다. </br>

![캡처](https://user-images.githubusercontent.com/43857226/69412674-b6963c80-0d52-11ea-8e7c-99540c12c31a.PNG) </br>

보자 멤버함수가 아니니 당연히 클래스 내 멤버변수 내 접근이 불가능하다. </br>
static 함수내에서 static 변수가 아닌 변수는 접근 불가하다. </br>
즉 다릏게 말하자면 </br>

> static 함수안에선 static 변수만 호출가능하다. </br>

라고 결론이 도출된다. </br>
이를 활용하면 전역변수와 전역함수를 대체할 수 있다. </br>
</br>
다음과 같이 const 와 static을 함께쓰면 정의와함께 초기화할 수 있다. </br>

![캡처](https://user-images.githubusercontent.com/43857226/69417666-7936ac80-0d5c-11ea-9954-4ceca408614c.PNG) </br>

const static멤버변수는 클래스가 정의될 때 지정된 값이 유지되는 상수 </br>




