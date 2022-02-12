#include "jass_string.h"

string_fake::string_fake()
{
	memory_[2] = (uint32_t)&memory_[0];
	memory_[7] = 0;
}

string_fake::string_fake(const char *str)
{
	memory_[2] = (uint32_t)&memory_[0];
	memory_[7] = (uint32_t)&str[0];
}

string_fake::string_fake(const string_fake &that)
{
	memory_[2] = (uint32_t)&memory_[0];
	memory_[7] = that.memory_[7];
}

string_fake::string_fake(string_fake &&that)
{
	memory_[2] = (uint32_t)&memory_[0];
	memory_[7] = that.memory_[7];
}

string_fake::~string_fake()
{
	memory_[7] = 0;
}

string_fake::operator jstring_t() const
{
	return (jstring_t)memory_;
}

string_fake &string_fake::operator=(const char *str)
{
	memory_[7] = (uint32_t)&str[0];
	return *this;
}

string_fake &string_fake::operator=(const string_fake &that)
{
	if (this != &that)
	{
		memory_[7] = that.memory_[7];
	}
	return *this;
}

string_fake &string_fake::operator=(string_fake &&that)
{
	if (this != &that)
	{
		memory_[7] = that.memory_[7];
	}
	return *this;
}

char *string_fake::c_str()
{
	return (char *)this->memory_[7];
}

jstring_fake::jstring_fake()
{
	this->value = nullptr;
}

jstring_fake::jstring_fake(string_fake* str)
{
	this->value = str;
}

char *from_string(jstring_t val)
{
	if (!val)
	{
		return nullptr;
	}

	val = *(uint32_t *)((uint32_t)val + 8);

	if (!val)
	{
		return nullptr;
	}

	return (char *)(*(uint32_t *)(val + 28));
}