insert into Vol values ('AF8810','PARIS','FES',09,30,11,15,0);
insert into Vol values ('AF8809','FES','PASRIS',13,30,15,15,0);
insert into vol values ('JW202','TUNIS','ALLMAGNE',08,00,10,15,0);
insert into vol values ('JW201','ALLMAGNE','TUNIS',12,30,15,15,0);

insert into Appareil values ('AB3','AIRBUS A300',180);
insert into Appareil values ('74E','BOEING 747-400 COMBI',150);
insert into Appareil values ('74L','BOEING 747-100',100);
insert into Appareil values ('SSC','CONCORDE',80);
insert into Appareil values ('734','BOEING 737-400',450);
insert into Appareil values ('741','BOEING 737-100',100);

insert into Pilote values (1333,'MARTIN','PARIS',30000.00,null,to_date('01-mar-1992','dd-mm-yyyy'));
insert into Pilote values (6723,'JHON','PARIS',25000.00,null,to_date('05-mar-1993','dd-mm-yyyy'));
insert into Pilote values (6589,'MARIO','ITALY',30000.00,null,to_date('03-mar-1991','dd-mm-yyyy'));

insert into Avion values (8832,'734',1988,'Ville de paris','16000:00');
insert into Avion values (8567,'734',1988,'Ville de bordeaux','8000:00');
insert into Avion values (8467,'734',1995,'Le sud','600:00');
insert into Avion values (7693,'741',1988,'Pacifique','34000:00');
insert into Avion values (8556,'AB3',1989,null,'12000:00');
insert into Avion values (8432,'AB3',1991,'Malte','10600:00');
insert into Avion values (8118,'74E',1992,null,'11800:00');
insert into Avion values (8767,'74L',1993,null,'10800:00');

insert into Affectation values ('JW201',to_date('01-mar-1994','dd-mm-yyyy'),6723,8767,310);
insert into Affectation values ('AF8810',to_date('02-may-1994','dd-mm-yyyy'),6589,7693,88);

commit;