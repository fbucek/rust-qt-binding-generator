/* generated by rust_qt_binding_generator */
#include "test_object_types_rust.h"

namespace {
    struct qbytearray_t {
    private:
        const char* data;
        int len;
    public:
        qbytearray_t(const QByteArray& v):
            data(v.data()),
            len(v.size()) {
        }
        operator QByteArray() const {
            return QByteArray(data, len);
        }
    };
    struct qstring_t {
    private:
        const void* data;
        int len;
    public:
        qstring_t(const QString& v):
            data(static_cast<const void*>(v.utf16())),
            len(v.size()) {
        }
        operator QString() const {
            return QString::fromUtf8(static_cast<const char*>(data), len);
        }
    };
    struct qmodelindex_t {
        int row;
        quintptr id;
    };
}
typedef void (*qstring_set)(QString*, qstring_t*);
void set_qstring(QString* v, qstring_t* val) {
    *v = *val;
}
typedef void (*qbytearray_set)(QByteArray*, qbytearray_t*);
void set_qbytearray(QByteArray* v, qbytearray_t* val) {
    *v = *val;
}

extern "C" {
    ObjectInterface* object_new(Object*, void (*)(Object*), void (*)(Object*), void (*)(Object*), void (*)(Object*), void (*)(Object*));
    void object_free(ObjectInterface*);
    bool object_boolean_get(ObjectInterface*);
    void object_boolean_set(void*, bool);
    int object_integer_get(ObjectInterface*);
    void object_integer_set(void*, int);
    uint object_uinteger_get(ObjectInterface*);
    void object_uinteger_set(void*, uint);
    void object_string_get(ObjectInterface*, QString*, qstring_set);
    void object_string_set(void*, qstring_t);
    void object_bytearray_get(ObjectInterface*, QByteArray*, qbytearray_set);
    void object_bytearray_set(void*, qbytearray_t);
};
Object::Object(QObject *parent):
    QObject(parent),
    d(object_new(this,
        [](Object* o) { emit o->booleanChanged(); },
        [](Object* o) { emit o->integerChanged(); },
        [](Object* o) { emit o->uintegerChanged(); },
        [](Object* o) { emit o->stringChanged(); },
        [](Object* o) { emit o->bytearrayChanged(); })) {}

Object::~Object() {
    object_free(d);
}
bool Object::boolean() const
{
    return object_boolean_get(d);
}
void Object::setBoolean(bool v) {
    object_boolean_set(d, v);
}
int Object::integer() const
{
    return object_integer_get(d);
}
void Object::setInteger(int v) {
    object_integer_set(d, v);
}
uint Object::uinteger() const
{
    return object_uinteger_get(d);
}
void Object::setUinteger(uint v) {
    object_uinteger_set(d, v);
}
QString Object::string() const
{
    QString v;
    object_string_get(d, &v, set_qstring);
    return v;
}
void Object::setString(const QString& v) {
    object_string_set(d, v);
}
QByteArray Object::bytearray() const
{
    QByteArray v;
    object_bytearray_get(d, &v, set_qbytearray);
    return v;
}
void Object::setBytearray(const QByteArray& v) {
    object_bytearray_set(d, v);
}
