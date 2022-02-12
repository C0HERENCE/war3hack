#ifndef JASS_JASS_STRING_H
#define JASS_JASS_STRING_H

#include <cstdint>
typedef uint32_t jstring_t;

class string_fake
{
public:
	string_fake();
	string_fake(const char *str);
	string_fake(const string_fake &that);
	string_fake(string_fake &&that);
	~string_fake();
	operator jstring_t() const;
	string_fake &operator=(const char *str);
	string_fake &operator=(const string_fake &that);
	string_fake &operator=(string_fake &&that);
	char *c_str();

private:
	uint32_t memory_[8];
};

class jstring_fake
{
public:
	char pad[0x8];
	string_fake* value;
	jstring_fake();
	jstring_fake(string_fake *that);
};

char *from_string(jstring_t val);

#endif