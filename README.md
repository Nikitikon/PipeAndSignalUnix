# PipeAndSignalUnix
Задание
Разработать программу, вычисляющую плотность нормального распределения в точке x по формуле f(x)=Exp(-x2/2)/Sqrt(2*Пи). 
Для нахождения Пи и Exp(-x2/2) программа должна породить два параллельных процесса, вычисляющих эти величины путем разложения в ряд по формулам вычислительной математики.
http://ru.wikipedia.org/wiki/Pi



Разработать программу, с учетом следующих требований:

	•	все действия, относящиеся как к родительскому процессу, так и к порожденным процессам, выполняются в рамках одного исполняемого файла; 
	
	•	обмен данными между процессом-родителем и процессом-потомком предлагается выполнить посредством временного файла: процесс-родитель после порождения процесса-потомка постоянно опрашивает временный файл, ожидая появления в нем информации от процесса-потомка; 
	
	•	если процессов-потомков несколько, и все они подготавливают некоторую информацию для процесса-родителя, каждый из процессов помещает в файл некоторую структурированную запись, при этом в этой структурированной записи содержатся сведения о том, какой процесс посылает запись, и сама подготовленная информация.
	
	•	Ни в коем случае не вычислять факториал отдельной функцией, а делать это в цикле подсчета суммы ряда находящегося в знаменателе, т.е., например, x=2, тогда ряд будет такой 1 – 2 + 2*2/1*2 – 4*2/2*3 + 8*2/6*4 и т.д., т.е. каждый элемент суммы домножается на X, а затем делится на N.
	
Домашняя работа

После отладки данной программы Модифицировать ее с учетом следующих требований:

	•	действия процесса-потомка реализуются отдельной программой, запускаемой по одному из системных вызовов execl(), execv() и т.д. из процесса-потомка; 
	
	•	процесс-потомок, после порождения, должен начинать и завершать свое функционирование по сигналу, посылаемому процессом-предком (это же относится и к нескольким процессам-потомкам); 
	
	•	обмен данными между процессами необходимо осуществить через программный канал. 
