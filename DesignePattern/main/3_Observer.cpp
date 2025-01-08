
#include <iostream>
#include <vector>
#include <string>

// Observer Interface
class Observer
{
public:
	virtual void update(int data) = 0;	// ���� �����Լ�
	virtual ~Observer() = default;		// ���� �Ҹ���
    std::string name = "Chart";
};

// Subobject
class ExcelSheet
{
private:
	std::vector<Observer*> observers;
	int data;

public:
    ExcelSheet() : data(0) // ������: �ʱ� ������ ���� 0
    {
        std::cout << "[ Create Excel Sheet ]" << std::endl;
    }   

    // Observer ��� �޼���
    // - ���ο� Observer�� ����Ͽ� ���� ���� �˸��� ���� �� �ֵ��� �߰�
    void attach(Observer* observer) 
    {
        observers.push_back(observer);
        std::cout << "Register : " << observer->name << std::endl;
    }

    // ������ ���� �˸� �޼���
    // - ��ϵ� ��� Observer�� update() �޼��带 ȣ���Ͽ� ������ ���� ������ �˸�
    void notify() 
    {
        for (Observer* observer : observers) 
        {
            observer->update(data); // �� Observer���� �����͸� ����
        }
    }

    // ������ ���� �޼���
    // - �����͸� �����ϰ� ���� ������ ��� Observer���� �˸�
    void setData(int newData) 
    {
        data = newData;  // ���ο� �����ͷ� ����
        std::cout << "ExcelSheet: Data updated to " << data << std::endl;
        notify();   // Observer�鿡�� �˸�
    }
};

// ��ü���� Observer Ŭ����_1
// - BarChart (���� ��Ʈ)
// - �����͸� ���� �׷����� ǥ��
class BarChart : public Observer 
{
public:
    BarChart()
    {
        name += "(Type: Bar)";
        std::cout << "[ Create " + name + " ]" << std::endl;
    }

    void update(int data)   // ������ ������Ʈ �� ȣ���
    {
        std::cout << "BarChart: Displaying data as vertical bars: ";
        for (int i = 0; i < data; ++i) 
        {
            std::cout << "|";   // ������ ����ŭ ���� ���
        }
        std::cout << " (" << data << ")" << std::endl;
    }
};

// ��ü���� Observer Ŭ����_2
// - LineChart (���� ��Ʈ)
// - �����͸� ���� �׷����� ǥ��
class LineChart : public Observer {
public:
    LineChart()
    {
        name += "(Type: Line)";
        std::cout << "[ Create " + name + " ]" << std::endl;
    }

    void update(int data)   // ������ ������Ʈ �� ȣ���
    {                      
        std::cout << "LineChart: Plotting data as a line: ";
        for (int i = 0; i < data; ++i) 
        {
            std::cout << "-";   // ������ ����ŭ �� ���
        }
        std::cout << " (" << data << ")" << std::endl;
    }
};

// ��ü���� Observer Ŭ����_3
// - PieChart (���� ��Ʈ)
// - �����͸� ���� �׷����� ǥ��
class PieChart : public Observer 
{
public:
    PieChart()
    {
        name += "(Type: Pie)";
        std::cout << "[ Create " + name + " ]" << std::endl;
    }

    void update(int data)   // ������ ������Ʈ �� ȣ���
    {
        std::cout << "PieChart: Displaying data as a pie chart slice: ";
        std::cout << "Pie [" << data << "%]" << std::endl; // ������ �� ��� (����: % ������ ǥ��)
    }
};


int main()
{
    // Subject ����
    ExcelSheet excelSheet;                       // �����͸� �����ϴ� ���� ��Ʈ ��ü ����

    std::cout << "\n\n";

    // Observer ��ü ���� (�� ��Ʈ ��ü)
    BarChart* barChart = new BarChart();         // ���� ��Ʈ ����
    LineChart* lineChart = new LineChart();      // ���� ��Ʈ ����
    PieChart* pieChart = new PieChart();         // ���� ��Ʈ ����

    std::cout << "\n\n";

    // Observer ���
    // - �� ��Ʈ(Observer)�� ���� ��Ʈ(Subject)�� ���
    excelSheet.attach(barChart);
    excelSheet.attach(lineChart);
    excelSheet.attach(pieChart);

    std::cout << "\n\n";

    // ������ ���� �׽�Ʈ
    // - �����͸� �����ϸ� ��ϵ� ��� Observer���� �˸��� �ް� ȭ�鿡 ����
    excelSheet.setData(5);                       // ������ ����: 5
    std::cout << "\n\n";
    excelSheet.setData(10);                      // ������ ����: 10

    // �޸� ����
    // - ���� �Ҵ�� Observer(��Ʈ) ��ü ����
    delete barChart;
    delete lineChart;
    delete pieChart;

    return 0;
}