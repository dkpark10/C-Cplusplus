# 콘스트에 대하여
</br>

![classconst](https://user-images.githubusercontent.com/43857226/68685313-4bf43c80-05ad-11ea-8c63-726398d48009.PNG) </br>
</br>

21번째 줄을보자 빨간 줄이 그어져 있다.  </br>
const 는 이 함수내 멤버변수의 변경을 불허한다. 라는 뜻이다. </br>
멤버변수의 저장된 값을 변경하지 않겠다라는 뜻. !!!</br>
이렇게 const를 선언하면 실수로 멤버변수의 값을 변경했을 때 </br>
컴파일 에러가 발생하고 에러를 확인할 수 있다. 실수를 최소화한다. </br>
 </br>
![classconst2](https://user-images.githubusercontent.com/43857226/68685318-4d256980-05ad-11ea-8726-76c131a062a8.PNG) </br>
 </br>
 
 const 선언을 통해 값을 변경하지 않아도 29줄에 빨간줄이 뜬다.  </br>
 const 함수내에서는 const가 아닌 함수의 호출이 제한된다.  </br>
 위 이미지에서 GetProtein함수는 의도치 않은 실수로 언제든지 변경될 수 있다. </br>
 그래서 멤버변수 변경을 막기위해 const 내부 함수에서 const가 아닌 함수의  </br>
 호출을 제한하는 것이다.
 
