create or replace procedure insert_audit( numav Avion.nuavion%type )
is
begin
    insert into Audit_Avion values (numav,to_date(TO_CHAR(SYSDATE, 'dd-mm-yyyy'),'dd-mm-yyyy'),TO_CHAR(SYSDATE, 'hh24:mi'),0);
    exception
        when DUP_VAL_ON_INDEX then
            dbms_output.put_line('avion nu '|| numav || ' deja existant');
end insert_audit;

create or replace procedure update_audit( numav Avion.nuavion%type )
is
begin
    update Audit_Avion set der_maj_date=to_date(TO_CHAR(SYSDATE, 'dd-mm-yyyy'),'dd-mm-yyyy'),der_maj_heure=TO_CHAR(SYSDATE, 'hh24:mi'),nbr_modif=nbr_modif+1 where nuavion=numav;
    if (sql%rowcount = 0) then
                DBMS_OUTPUT.PUT_LINE('no rows were updated!');
    end if;
end; 

create or replace procedure init_audit
is
    numav Avion.nuavion%type;
    cursor curaud
    is
        select nuavion from Avion;
begin
    open curaud;
    loop
        fetch curaud into numav;
        exit when curaud%notfound;
        ajout_audit(numav);
    end loop;
    close curaud;
end init_audit;

begin
    init_audit;
end;