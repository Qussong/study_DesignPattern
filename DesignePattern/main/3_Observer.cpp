
#include <iostream>
#include <vector>
#include <string>

// Observer Interface
class Observer
{
public:
	virtual void update(int data) = 0;	// 순수 가상함수
	virtual ~Observer() = default;		// 가상 소멸자
    std::string name = "Chart";
};

// Subobject
class ExcelSheet
{
private:
	std::vector<Observer*> observers;
	int data;

public:
    ExcelSheet() : data(0) // 생성자: 초기 데이터 값은 0
    {
        std::cout << "[ Create Excel Sheet ]" << std::endl;
    }   

    // Observer 등록 메서드
    // - 새로운 Observer를 등록하여 변경 사항 알림을 받을 수 있도록 추가
    void attach(Observer* observer) 
    {
        observers.push_back(observer);
        std::cout << "Register : " << observer->name << std::endl;
    }

    // 데이터 변경 알림 메서드
    // - 등록된 모든 Observer의 update() 메서드를 호출하여 데이터 변경 사항을 알림
    void notify() 
    {
        for (Observer* observer : observers) 
        {
            observer->update(data); // 각 Observer에게 데이터를 전달
        }
    }

    // 데이터 설정 메서드
    // - 데이터를 변경하고 변경 사항을 모든 Observer에게 알림
    void setData(int newData) 
    {
        data = newData;  // 새로운 데이터로 갱신
        std::cout << "ExcelSheet: Data updated to " << data << std::endl;
        notify();   // Observer들에게 알림
    }
};

// 구체적인 Observer 클래스_1
// - BarChart (막대 차트)
// - 데이터를 막대 그래프로 표현
class BarChart : public Observer 
{
public:
    BarChart()
    {
        name += "(Type: Bar)";
        std::cout << "[ Create " + name + " ]" << std::endl;
    }

    void update(int data)   // 데이터 업데이트 시 호출됨
    {
        std::cout << "BarChart: Displaying data as vertical bars: ";
        for (int i = 0; i < data; ++i) 
        {
            std::cout << "|";   // 데이터 값만큼 막대 출력
        }
        std::cout << " (" << data << ")" << std::endl;
    }
};

// 구체적인 Observer 클래스_2
// - LineChart (라인 차트)
// - 데이터를 선형 그래프로 표현
class LineChart : public Observer {
public:
    LineChart()
    {
        name += "(Type: Line)";
        std::cout << "[ Create " + name + " ]" << std::endl;
    }

    void update(int data)   // 데이터 업데이트 시 호출됨
    {                      
        std::cout << "LineChart: Plotting data as a line: ";
        for (int i = 0; i < data; ++i) 
        {
            std::cout << "-";   // 데이터 값만큼 선 출력
        }
        std::cout << " (" << data << ")" << std::endl;
    }
};

// 구체적인 Observer 클래스_3
// - PieChart (파이 차트)
// - 데이터를 파이 그래프로 표현
class PieChart : public Observer 
{
public:
    PieChart()
    {
        name += "(Type: Pie)";
        std::cout << "[ Create " + name + " ]" << std::endl;
    }

    void update(int data)   // 데이터 업데이트 시 호출됨
    {
        std::cout << "PieChart: Displaying data as a pie chart slice: ";
        std::cout << "Pie [" << data << "%]" << std::endl; // 데이터 값 출력 (가정: % 비율로 표현)
    }
};


int main()
{
    // Subject 생성
    ExcelSheet excelSheet;                       // 데이터를 관리하는 엑셀 시트 객체 생성

    std::cout << "\n\n";

    // Observer 객체 생성 (각 차트 객체)
    BarChart* barChart = new BarChart();         // 막대 차트 생성
    LineChart* lineChart = new LineChart();      // 라인 차트 생성
    PieChart* pieChart = new PieChart();         // 파이 차트 생성

    std::cout << "\n\n";

    // Observer 등록
    // - 각 차트(Observer)를 엑셀 시트(Subject)에 등록
    excelSheet.attach(barChart);
    excelSheet.attach(lineChart);
    excelSheet.attach(pieChart);

    std::cout << "\n\n";

    // 데이터 변경 테스트
    // - 데이터를 변경하면 등록된 모든 Observer들이 알림을 받고 화면에 갱신
    excelSheet.setData(5);                       // 데이터 변경: 5
    std::cout << "\n\n";
    excelSheet.setData(10);                      // 데이터 변경: 10

    // 메모리 해제
    // - 동적 할당된 Observer(차트) 객체 삭제
    delete barChart;
    delete lineChart;
    delete pieChart;

    return 0;
}