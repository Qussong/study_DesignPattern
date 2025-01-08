<!-- https://teamsparta.notion.site/3-1-1422dc3ef51481ed8b3eddf468cd2659 -->
# 📌디자인 패턴

### Singleton (생성 패턴)

**🔻문제 상황**

<img src="/img/singleton_airplane-game.png" width="">

비행기 게임을 만들려고 한다.</br>
게임내 제어하는 비행기는 반드시 하나만 존재 해야한다.</br>

**🔻요구 사항**

```
1. 비행기 관리
- 게임 내 비행기는 오직 하나만 존재한다.
- 비행기의 초기 위치는 (0,0) 

2. 비행기 이동
- 비행기는 move(int deltaX, int deltaY) 메서드를 통해 이동 하고, 위치를 업데이트 한다.
- 현재 비행기 좌표를 확인할 수 있는 getPosition() 을 제공한다.
```

**🔻해결 방법**

비행기 게임을 혼자 하는데 여러개의 비행기를 제어해야 하는 경우는 없다.
게임내에서 비행기가 하나만 존재하도로 구현하기위해 `싱글톤 패턴`을 활용한다.

<img src="/img/singleton_airplane_uml.png" width="">

- [Singleton 코드 URL](https://github.com/Qussong/study_DesignPattern/blob/main/DesignePattern/main/1_Sigleton.cpp)
- [Singleton 코드 해설 URL](https://github.com/Qussong/study_DesignPattern/blob/main/DesignePattern/main/1_Singleton.md)

---

### Decorator (구조 패턴)

**🔻문제 상황**

<img src="/img/decorator_pizza.png" width="">

피자를 만들려고 한다.</br>
피자의 토핑을 원하는 대로 추가하면서 동적으로 피자를 만들 수 있어야한다.</br>
어떻게 하면 객체의 상태를 동적으로 업데이트 할 수 있는가?</br>

**🔻요구 사항**

```
1. 기본 피자
- 피자의 기본 베이스가 반드시 필요 합니다.
- 기본 피자에는 이름과 가격이 정의되어 있습니다.

2. 토핑 추가
- 피자에 토핑(치즈, 페퍼로니, 올리브)를 동적으로 추가할 수 있습니다.
- 토핑은 이름과 추가 비용을 가집니다.

3. 피자 정보 제공
- 최종 피자의 이름(기본 피자 + 추가된 토핑들)과 가격을 제공 합니다.
```

**🔻해결 방법**

디자인 패넌 중 구조 패턴 중 하나인 Decorator 를 활용한다.</br>
이를 활용하면 기존 코드 수정 없이, 클래스에 새로운 기능을 추가 및 확장할 수 있다.</br>

<img src="/img/decorator_pizza_uml.png" width="">

- [Decorator 코드 URL](https://github.com/Qussong/study_DesignPattern/blob/main/DesignePattern/main/2_Decorator.cpp)
- [Decorator 코드 해설 URL](https://github.com/Qussong/study_DesignPattern/blob/main/DesignePattern/main/2_Decorator.md)

---

### Observer (행동 패턴)

**🔻문제 상황**

<img src="/img/observer_chart.png" width="">

엑셀 프로그램을 만들려고 한다.</br>
엑셀 데이터 값을 변경할 때 해당 데이터로 생성한 모든 차트의 데이터가 반영되게 하고 싶다.</br>
차트의 개수나 종류가 많을때 매번 차트의 데이터를 수동으로 업데이트 하는것은 비효율적이다.</br>
어떻게 하면 이를 자동으로 할 수 있을까?</br>

**🔻요구 사항**

```
엑셀 시트와 차트 관리
- 엑셀 시트는 데이터를 입력 받을 수 있다.
- 여러 차트는 엑셀 데이터를 기반으로 업데이트 된다.
- 엑셀에 새로운 값이 입력되면 연결된 모든 차트가 자동으로 업데이트 된다.
```

**🔻해결 방법**

Observer 패턴을 활용하여 해결한다.</br>
Excel Sheet 를 Subobject 로 설정하고 이를 관찰하는 Observer 들로 다양한 Chart 들을 등록시켜준다.</br>
Excel Sheet에 변경내용이 생기면 Observer 에 변경사항을 알려주고, 알림을 받은 Observer 들은 변경사항을 반영한다.</br>

<img src="/img/observer_chart_uml.png" width="">

>- Subobject : 상태를 관리하고, 변경되었음을 Observer에 알림
>- Observer : Subobject를 관찰하며 상태 변경시 반응함

- [Decorator 코드 URL](https://github.com/Qussong/study_DesignPattern/blob/main/DesignePattern/main/3_Observer.cpp)
- [Decorator 코드 해설 URL](https://github.com/Qussong/study_DesignPattern/blob/main/DesignePattern/main/3_Observer.md)

