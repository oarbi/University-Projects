create or replace trigger ajout_audit
after insert on Avion
for each row
begin
    ajout_audit(:new.nuavion);
end;

create or replace trigger modif_audit
before update of nbhvol on Avion
for each row
begin
    modif_audit(:old.nuavion);
end;

create or replace trigger ajout_aff
before insert on Affectation
for each row
declare
    nbrlim number;
begin
    select app.nbrplaces into nbrlim from Appareil app,Avion av where (:new.nuavion=av.nuavion) and (av.codetype=app.codetype);
    if (:new.nbrpassagers > nbrlim) then
        raise_application_error(-20100,'le nbr passager est trop grand pour ce type d avion !');
    end if;
end;

create or replace trigger upd_aff
before update on Affectation
for each row
begin
    raise_application_error(-20100,'La modification est interdite !');
end;

create or replace trigger ajout_log_modif
after update on Avion
for each row
declare
    colcon varchar2(60):='';
begin
    if (:old.codetype != :new.codetype) then
        colcon :=colcon || ' codetype ';
    end if;
    if (:old.annserv != :new.annserv) then
        colcon :=colcon || ' annserv ';
    end if;
    if (:old.entrepot != :new.entrepot) then
        colcon :=colcon || ' entrepot ';
    end if;
    if (:old.nbhvol != :new.nbhvol) then
        colcon :=colcon || ' nbhvol ';
    end if;
    insert into LogAvion values(idlog.nextval,'Modification',:old.nuavion,to_date(TO_CHAR(SYSDATE, 'dd-mm-yyyy'),'dd-mm-yyyy'),TO_CHAR(SYSDATE, 'hh24:mi'),colcon);
end;

create or replace trigger ajout_log_suppr
after delete on Avion
for each row
begin
    insert into LogAvion values(idlog.nextval,'Suppression',:old.nuavion,to_date(TO_CHAR(SYSDATE, 'dd-mm-yyyy'),'dd-mm-yyyy'),TO_CHAR(SYSDATE, 'hh24:mi'),null);
end;

create or replace trigger ajout_log_ins
after insert on Avion
for each row
begin
    insert into LogAvion values(idlog.nextval,'Insertion',:new.nuavion,to_date(TO_CHAR(SYSDATE, 'dd-mm-yyyy'),'dd-mm-yyyy'),TO_CHAR(SYSDATE, 'hh24:mi'),'Tous');
end;