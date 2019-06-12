#ifndef TABLE
#define TABLE

class ConstBase
{
	struct numberNode
	{
		double value;
		struct numberNode* next;
	} numberList;
	struct stringNode
	{
		const char value[];
		struct numberNode* next;
	} stringList;

	ConstBase();
	~ConstBase();

	struct numberNode* index(double x);
	struct stringNode* index(const char x[]);
};
class Table
{
	enum class Type : int
	{
		NUMBER = 0,
		STRING = 1,
		TABLE = 2,
		FUNCTION = 3,
	};
	class Element
	{
		Type type;
		void create(int x);
		void create(double x);
		void create(const char x[]);
		int* ptr;
	};
	class Tuple
	{

	};
};

#endif
