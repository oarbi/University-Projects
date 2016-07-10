create table LogAvion(idop number,typeop varchar2(20),nuavion number ,datemodif date, heuremodif varchar2(5),colonneconserne varchar2(20),
constraint pk_la primary key (idop),
check (typeop in ('Suppression','Modification','Insertion')));

drop table logavion;