#include "CTTR/Data.h"

void Data::SetScriptAlias(const char*) {}

void DataBoolean::SetValue(bool value) {}

bool DataBoolean::GetValue() {}

void DataNumber::SetValue(f32 value) {}

f32 DataNumber::GetValue() {}

void DataObject::SetValue(core::IRefCount value) {}

core::IRefCount DataObject::GetValue() {}

void DataString::SetValue(const char* value) {}

const char* DataString::GetValue() {}
