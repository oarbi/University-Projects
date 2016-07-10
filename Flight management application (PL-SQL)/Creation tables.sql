create table Avion (nuavion number, codetype varchar2(3), annserv number(4) not null,entrepot varchar2(20),nbhvol varchar2(20) not null,
constraint pk_avion primary key (nuavion),
constraint fk_ct foreign key (codetype) references Appareil(codetype));

create table Affectation (nuvol varchar2(10),datevol date not null,nupilote number ,nuavion number ,nbrpassagers number not null,
constraint pk_aff primary key (nuvol,datevol),
constraint fk_vol foreign key (nuvol) references Vol (nuvol),
constraint fk_pil foreign key (nupilote) references Pilote (nupilote),
constraint fk_av foreign key (nuavion) references Avion (nuavion));

create table Vol (nuvol varchar2(10),villedep varchar2(20) not null,villearr varchar2(20) not null,depheure number(2) not null,depmin number(2) not null,arrheure number(2) not null,arrmin number(2) not null,jourarr number(1) not null,
constraint pk_vol primary key (nuvol),
check ( depheure between 0 and 23 ),
check ( arrheure between 0 and 23 ),
check ( depmin between 0 and 59 ),
check ( arrmin between 0 and 59 ));

create table Pilote (nupilote number ,nom varchar2(10) not null,adress varchar2(30) not null,salaire number not null,comm varchar2(60) ,datembauche date not null,
constraint pk_pil primary key (nupilote));

create table Appareil (codetype varchar2(3),famille varchar2(20) not null, nbrplaces number not null,
constraint pk_app primary key (codetype));

commit;