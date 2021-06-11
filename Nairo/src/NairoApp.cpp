#include <Kanairo.h>

class Nairo : public Kanairo::Application
{
public:
	Nairo()
	{

	}
	~Nairo()
	{

	}
};

Kanairo::Application* Kanairo::CreateApplication()
{
	return new Nairo();
}