[ex00]
1. Bureaucrat class
	member variable: name, grade
	member function: getName, getGrade

2. User definded exceptional cases
	if (grade < 1)
	= Bureaucrat::GradeTooHighException

	if (grade > 150)
	= Bureaucrat::GradeTooLowException

3. Overrideing function '<<'
	To 'ostream' by using '<<' print out as below ref.
	<name>, bureaucrat grade <grade>

4. Caution
	const char* -> use 'literal' value.
	
[ ex01 ]
1. Goal
    Make the "Form" class
        [ Memeber Variable ]
        1. mName
        2. singGrade
        3. execGrade
        4. isSigned
    
        [ OCCF ]
        1. Default constructor
        2. Destructor
        3. Copy constructor
        4. Overloaded assignment operator
        5. Parameterized constructor
        
        [ Method ]
        1. getName
        2. getSignGrade
        3. getExecGrade
        4. getIsSigned
        5. beSigned() // Bureaucrat가 Form 서명 가능한지 확인 후 가능하면 서명.

        Exceptional case
        1. GradeTooHighException
        2. GradeTooLowException
        
[ ex02 ]
[ Goal ]
 1. Make class
 	Bureaucrat
 	Form
 	RobotomyRequestForm
 	ShrubberyCreationForm
 	PresidentialPardonForm

 2. Method
 	signForm()
 	executeForm()

[ Background ]
클래스에 **하나라도 순수 가상 함수(pure virtual function)**를 선언하면
그 클래스는 **추상 클래스(abstract class)**가 된다.
= 추상 클래스는 인스턴스를 직접 만들 수 없다.

[ In short ]
			sign	exec	Mainpoint
RobotomyRequestForm	72	45	재미와 불확실성을 주는 작업
= Make for the target to sound "Drill", print the chance to 50% success or fail.
= Robotomy (로봇화)

			sign	exec	Mainpoint
ShrubberyCreationForm	145	137	창의적이고 상징적인 작업
= "Shrubbery"means plant, tree.
= Make the ASCII formed tree from this form.

			sign	exec
PresidentialPardonForm	25	5
= target에게 "Zaphod Beeblebrox"라는 인물에 의해 사면(Pardon)이 부여되었다고 알린다.
= Zaphod Beeblebrox: 은하수를 여행하는 히치하이커를 위한 안내서"에서 등장하는 캐릭터.

			sign	exec
Intern			X	X
= form을 채우는 귀찮은 일 bureaucrat들에게 하라고 할 수 없다.
= Intern에게 시킨다.

[ ex03 ]
 Difference between (ex02 & ex03)
 
 			ex02			ex03
1. Make Form		new			Intern
2. Factory pattern	X			Intern::makeForm()
3. Flexibility		X			Based on the string, dynamic make availble.

 	ex02: new()
 	= Form 객체를 만들 때 직접 new 연산자를 사용
 	=  "어떤 폼을 만들지 미리 알고 있어야 함."
 	
 	ex03: Intern::makeForm()
 	= 스트링 기반으로 상황에 따라 폼을 만들 수 있음.

4. Manage memory	new, delete		makeForm(), delete
5. How to use		Form *f = new()		Form *f = intern.makeForm("robotomyrequest","Target");
6. What i learned	Inherit, polymorphism	Factory pattern(Intern)
