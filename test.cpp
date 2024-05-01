#include <cstdint>
#include <vector>


#define isEven(x) x%2==0

/*
 * Реализована через директиву препроцессора:
 * Плюсы: нет дополнительного запроса на вызов функции, так как код встраивается, работает со всеми типами данных
 * Минусы: нет
 * bool isEven(int value){return value%2==0;}
 * Минусы: из-за реализации в виде функции происходит дополнительное обращение к памяти на выгрузку функции и ее вызов, работает только с типом данных int
 * Плюсы: сомнительны
 */


class circleBuffer1{
public:
	circleBuffer1(uint64_t size){
		circleBufferSize = size;
		circleBuffer.resize(size);
	}
	int getCircleBufferItem(){
		int result = circleBuffer[pointer];
		pointer++;
		pointer %= circleBufferSize;
		return result;
	}
	void addCircleBufferItem(int item){
		circleBuffer.push_back(item);
		circleBufferSize++;
	}
private:
	uint64_t circleBufferSize;
	std::vector<int> circleBuffer;
	int pointer = 0;
};


#define CIRCLE_BUFFER_ITEM_INT 0
#define CIRCLE_BUFFER_ITEM_FLOAT 1
#define CIRCLE_BUFFER_ITEM_CHAR 2

typedef struct{
	uint8_t vType;
	void* value;

} circleBufferItem_t;


class circleBuffer2{
public:
	circleBuffer(uint64_t size){
		circleBufferSize = size;
		circleBuffer.resize(size);
	}
	std::vector<void*> getCircleBufferItem(){
		std::vector<void*> result{(void*)circleBuffer[pointer].vType,circleBuffer[pointer].value};
		pointer++;
		pointer %= circleBufferSize;
		return result;
	}
	void addCircleBufferItem(circleBufferItem_t item){
		circleBuffer.push_back(item);
		circleBufferSize++;
	}
private:
	uint64_t circleBufferSize;
	std::vector<circleBufferItem_t> circleBuffer;	
	int pointer = 0;
};

/*
 * первый буфер реализован только для целочисленных, во втором могут хранится данные произвольных типов
 * Плюсы первой реализации: не требует, чтобы пользователь задумывался о типе данных; Минусы: ограничен типом данных int
 * Плюсы второго буфера: произвольный тип данных; Минусы: необходимо следить за поступающими данными
 */


void sort(std::vector<int> enterArray)
{
	for(int i = 0; i < enterArray.size(); i++)
	{
		for(int j = i+1; j < enterArray.size(); i++)
		{
			if(enterArray[i] > enterArray[j])
			{
				int temp = enterArray[j];
				enterArray[j] = enterArray[i];
				enterArray[i] = temp;
			}
		}
	}
}

/*
 * Сложность алгоритма (n^2)/2, что значительно хуже, чем nlogn, однако если учитывать, что данный алгоритм
 * не требует выделения памяти, то выполнение одной операции перемещения данных в памяти составит ~15 процессорных циклов,
 * тогда как, алгоритмы со скоростью nlogn занимают примерно столько же процессорных циклов + стек вызовов функций + запрос системе на выделение памяти
 */

