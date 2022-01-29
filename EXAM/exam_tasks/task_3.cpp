#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>

/*
Существует 3 вида частей речи 
Существительное 
Глагол
Прилагательное 
Исользую словарь, мы можем проверять попадание под шаблон введенного в классы DeclarativeSentence и InterrogativeSentence предложения
*/

class WordsList //класс словарь
{
private:
	std::map<std::string, std::string> wordList; //{Слово, Часть речи} Пример:{"Qiānbǐ","Существительное"}
public:
	WordsList(const std::string& wordsBaseFileName);//конструктор с параметром: загружает некоторую базу данных слов из файла (реализация по заданию не нужна)
	const std::string& getPartOfSpeech(const std::string& _word) const
	{
		for(auto word : wordList)
			if(word.first == _word)
				retun word.second;
		return "";
	}//first - слово, second - часть речи: если слово совпало с некоторым словом из словаря - вернуть часть речи, иначе вернуть пустую строку
}



class Phrase//абстрактный класс фраза
{
protected:
	const std::string keyWord;
public:
	Phrase() : keyWord("de") {}
	virtual ~Phrase() = default;
	virtual const std::string& getType() const = 0;//переопределение оставляет дочерним
	virtual bool checkCorrectTemplate() = 0;//переопределение оставляем дочерним
	virtual unsigned getLenght() const = 0;//переопределение оставляем дочерним
	virtual void printSentence(std::ostream& out) const = 0;//переопределение оставляем дочерним
}

class DeclarativeSentence : public Phrase
{
private:
	std::string nounAsSubject;
	std::string pronounAsPartOfObject;
	const std::string keyWord1;
public:
	DeclarativeSentence() : Phrase(); //пустой конструктор
	DeclarativeSentence(const std::string& _nounAsSubject, const std::string& _pronounAsPartOfObject) : 
	Phrase(), nounAsSubject(_nounAsSubject), pronounAsPartOfObject(_pronounAsPartOfObject), keyWord1("shì") {} //конструктор с параметрами
	DeclarativeSentence(const DeclarativeSentence& other); //копирующий конструктор: получение копии объекта
	virtual ~DeclarativeSentence() = default;
	virtual const std::string& getType() const override { return "DeclarativeSentence"; }
	virtual bool checkCorrectTemplate() override; /*: по заданию не нужно, но можно проверять части речи переменных состояния класса через метод 
	getPartOfSpeech(const std::string& _word) const из словаря: true - слова соотвествуют своим частям речи, false - не соответсвуют*/
	virtual unsigned getLenght() const override; //получение длины предложения
	virtual void printSentence(std::ostream& out) const override;
	friend std::ostream& operator << (std::ostream& out, DeclarativeSentence& sentece);

}

DeclarativeSentence::DeclarativeSentence(const DeclarativeSentence& other) : Phrase(), keyWord1("shì")
{
	this->nounAsSubject = other.nounAsSubject;
	this->pronounAsPartOfObject = other.pronounAsPartOfObject;
}

unsigned DeclarativeSentence::getLenght() const 
{
	return strlen(nounAsSubject) + strlen(pronounAsPartOfObject) + strlen(keyWord1) + strlen(keyWord); //+2 потому что два пробела
}

void DeclarativeSentence::printSentence(std::ostream& out) const
{
	out << "Type: " << getType() << std::endl;
	out << "Sentence: " << nounAsSubject << " " << keyWord << " " << pronounAsPartOfObject << keyWord1 << std::endl;
}

std::ostream& operator << (std::ostream& out, DeclarativeSentence& sentece)
{
	sentece.printSentence(out);
	return out;
}

class InterrogativeSentence : public Phrase
{
private:
	std::string pronounAsSubject;
	std::string verb;
	std::string pronounAsPartOfDefForObject;
	std::string nounAsObject;
	std::string keyWord2;
public:
	InterrogativeSentence() : Phrase() {}
	InterrogativeSentence(const std::string& _pronounAsSubject,const std::string& _verb, const std::string& _pronounAsPartOfDefForObject, 
		const std::string& _nounAsObject) : Phrase(), pronounAsSubject(_pronounAsSubject), verb(_verb), pronounAsPartOfDefForObject(_pronounAsPartOfDefForObject),
		nounAsObject(_nounAsObject), keyWord2("ma?") {}
	InterrogativeSentence(const InterrogativeSentence& other);
	virtual ~InterrogativeSentence() = default;
	virtual const std::string& getType() const override { return "InterrogativeSentence"; }
	virtual bool checkCorrectTemplate() override; //аналогично, просто проверка других слов на другие части речи
	virtual unsigned getLenght() const override;//аналогично, просто проверка других слов на другие части речи
	virtual void printSentence(std::ostream& out) const override;
	friend std::ostream& operator << (std::ostream& out, InterrogativeSentence& sentece);
}

InterrogativeSentence::InterrogativeSentence(const InterrogativeSentence& other) : Phrase(), keyWord2("ma?")
{
	this->pronounAsSubject = other.pronounAsSubject;
	this->verb = other.verb;
	this->pronounAsPartOfObject = other.pronounAsPartOfObject;
	this->nounAsObject = other.nounAsObject;
}

unsigned InterrogativeSentence::getLenght() const{
	return strlen(pronounAsSubject) + strlen(verb) + strlen(pronounAsPartOfDefForObject) + strlen(nounAsObject) + strlen(keyWord1) + strlen(keyWord2) + 4;
}

void InterrogativeSentence::printSentence(std::ostream& out) const
{
	out << "Type: " << getType;
	out << "Sentence: " << pronounAsSubject << " " << verb << " " << pronounAsPartOfDefForObject << " " << keyWord << " " << nounAsObject << keyWord2 << std::endl;
}

std::ostream& operator << (std::ostream& out, InterrogativeSentence& sentece)
{
	sentece.printSentence(out);
	return out;
}

class Stack
{
private:
	std::vector<Phrase*> phraseList;
public:
	Stack() = default;//пустой конутрктор
	Stack(const std::vecotr& _phraseList) : phraseList(_phraseList) {} //конструктор с параметром std::vector
	~Stack() = default;//вектор сам под себя хорошо почистит память, поэтому дефолтный
	void pushBack(Phrase* _phrase);//добавление в стэк: т.к. это стэк, работает принцип последний зашел - первый вышел: можем добавлять и удалять только с конца
	void popBack();//выборка из стека: т.к. это стэк, работает принцип последний зашел - первый вышел: можем добавлять и удалять только с конца
	const std::vector<Phrase*>& getPhraseList() const { return phraseList; }
	unsigned getTotalLenght() const;
	void printStack() const;
}

void Stack::pushBack(Phrase* _phrase) {
	phraseList.push_back(_phrase);
} //указатель передается по значению
void Stack::popBack(){
	phraseList.pop_back();//удаляет последний элемент вектора, как я помню
	/*phraseList.erase(phraseList.end()) еще можно так*/
}
unsigned Stack::getTotalLenght() const
{
	unsigned result = 0;
	for(auto phrase : phraseList)
		result += phrase->getLenght();
	return result;
}

void Stack::printStack() const
{
	for(auto phrase : phraseList)
		phrase->printSentence();
}

int main()
{
	Stack stack;
	Phrase* phrase1 = new DeclarativeSentence("Qiānbǐ",  "tāde");
	Stack.pushBack(phrase1);
	Phrase* phrase2 = new InterrogativeSentence("Tā", "ài", "tā", "gŏu");
	Stack.pushBack(phras2);
	Stack.printStack();

}

