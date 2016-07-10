create or replace trigger suppr_avion
before delete on Avion
for each row 
declare
    davo date;
    nv Vol.nuvol%type;
    cursor cursupprav(na Avion.nuavion%type)
    is
        select nuvol,datevol from Affectation where (nuavion=na);
begin
    suppr_audit(:old.nuavion);
    open cursupprav(:old.nuavion);
    loop
        fetch cursupprav into nv,davo;
        exit when cursupprav%notfound;
        suppr_affectation(nv,davo);
    end loop;
end;

create or replace trigger suppr_vol
before delete on vol
for each row 
declare
    davo date;
    cursor cursupprvol(nv Vol.nuvol%type)
    is
        select datevol from Affectation where (nuvol=nv);
begin
    open cursupprvol(:old.nuvol);
    loop
        fetch cursupprvol into davo;
        exit when cursupprvol%notfound;
        suppr_affectation(:old.nuvol,davo);
    end loop;
    close cursupprvol;
end;

create or replace trigger suppr_pilote
before delete on Pilote
for each row 
declare
    nv Vol.nuvol%type;
    davo date;
    cursor cursupprpil(np Vol.nuvol%type)
    is
        select nuvol,datevol from Affectation where (nupilote=np);
begin
    open cursupprpil(:old.nupilote);
    loop
        fetch cursupprpil into nv,davo;
        exit when cursupprpil%notfound;
        suppr_affectation(nv,davo);
    end loop;
    close cursupprpil;
end;

create or replace trigger suppr_appareil
before delete on Appareil
for each row 
declare
    na Avion.nuavion%type;
    cursor cursupprapp(ct Appareil.codetype%type)
    is
        select nuavion from Avion where (codetype=ct);
begin
    open cursupprapp(:old.codetype);
    loop
        fetch cursupprapp into na;
        exit when cursupprapp%notfound;
        suppr_avion(na);
    end loop;
    close cursupprapp;
end;