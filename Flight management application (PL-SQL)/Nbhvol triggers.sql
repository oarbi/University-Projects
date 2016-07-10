create or replace trigger update_nbhvol
after insert on Affectation
for each row
declare
    nv AVION.NBHVOL%type;
    minnv number;
    dr number;
begin
    select av.nbhvol into nv from Avion av where (av.nuavion = :new.nuavion);
    minnv := to_number(substr(nv,1,instr(nv,':')-1))*60 + to_number(substr(nv,instr(nv,':')+1,2));
    dr :=to_number(to_char(to_date(duree(:new.nuvol),'hh:mi'),'hh'))*60 + to_number(to_char(to_date(duree(:new.nuvol),'hh:mi'),'mi'));
    update Avion set NBHVOL=to_char((trunc((minnv+dr)/60))||':'||(mod((minnv+dr),60))) where NUAVION=:new.nuavion;
end;

create or replace trigger update_nbhvol_del
after delete on Affectation
for each row
declare
    nv AVION.NBHVOL%type;
    minnv number;
    dr number;
begin
    select av.nbhvol into nv from Avion av where (av.nuavion = :old.nuavion);
    minnv := to_number(substr(nv,1,instr(nv,':')-1))*60 + to_number(substr(nv,instr(nv,':')+1,2));
    dr :=to_number(to_char(to_date(duree(:old.nuvol),'hh:mi'),'hh'))*60 + to_number(to_char(to_date(duree(:old.nuvol),'hh:mi'),'mi'));
    update Avion set NBHVOL=to_char((trunc((minnv-dr)/60))||':'||(mod((minnv-dr),60))) where NUAVION=:old.nuavion;
end;
