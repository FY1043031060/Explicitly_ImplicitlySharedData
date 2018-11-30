#include <QSharedData>
#include <QString>

class EmployeeData : public QSharedData
{
public:
    EmployeeData() : id(-1) { }
    EmployeeData(const EmployeeData &other)
        : QSharedData(other), id(other.id), name(other.name) { }
    ~EmployeeData() { }

    int id;
    QString name;
};

class Employee
{
public:
    Employee() { d = new EmployeeData; }
    Employee(int id, const QString &name) {
        d = new EmployeeData;
        setId(id);
        setName(name);
    }
    Employee(const Employee &other)
        : d (other.d)
    {
    }
    void setId(int id) { d->id = id; }
    void setName(const QString &name) { d->name = name; }

    int id() const { return d->id; }
    QString name() const { return d->name; }

private:
    QExplicitlySharedDataPointer<EmployeeData> d;   ////显式共享
    ////QSharedDataPointer<EmployeeData> d;         ////隐式共享
};

#include <QDebug>
int main(int argc, char *argv[])
{
    Employee e1(1001, "Tom");
    Employee e2 = e1;
    e1.setName("Jerry");
}
