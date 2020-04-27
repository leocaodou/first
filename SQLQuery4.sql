select Sno,Sname
from student
where Sno in
(
	select distinct Sno
	from SC x
	where not exists
	(
		select *
		from SC y
		where y.Sno='0821103' and not exists
		(
			select *
			from SC Z
			where z.Cno=y.Cno and 
			z.Sno=x.Sno
		)
	)
) and Sno <> '0821103';
