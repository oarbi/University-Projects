insert into Audit_Avion values (8832,to_date(TO_CHAR(SYSDATE, 'dd-mm-yyyy'),'dd-mm-yyyy'),TO_CHAR(SYSDATE, 'hh24'),0);

insert into Avion values (10,'734',1988,'Ville de paris',16000);

update Avion set nbhvol=19000,annserv=2000 where nuavion=10;

delete from Avion where nuavion=10;
