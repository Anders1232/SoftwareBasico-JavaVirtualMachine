#include "attribute_info.hpp"
#include <stdint.h>
#include<vector>

#ifndef FIELD_INFO_HPP
#define FIELD_INFO_HPP

using namespace std;

#ifndef ATTRIBUTE_INFO
class attribute_info;
#endif
#ifndef JAVA_CLASS
class JavaClass;
#endif
#ifndef CP_INFO
class cp_info;
#endif

#define FIELD_INFO
class field_info {

	private:

	uint16_t access_flags;
	uint16_t name_index;
	uint16_t descriptor_index;
	uint16_t attributes_count;
	vector<attribute_info *> attributes;

	public:

	field_info(FILE *arq, std::vector<cp_info*> const &constant_pool);
	void ExibirInformacoes(string tabs, JavaClass *javaClass);
	uint16_t getAccessFlags(void);
	uint16_t getNameIndex(void);
	uint16_t getDescriptorIndex(void);
};

#endif
