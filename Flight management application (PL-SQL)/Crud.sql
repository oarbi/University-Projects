-- Avion

create or replace procedure ajout_avion(na AVION.NUAVION%type,ct AVION.CODETYPE%type,ans AVION.ANNSERV%type,er AVION.ENTREPOT%type, nv AVION.NBHVOL%type)
is
begin
    insert into Avion values (na,ct,ans,er,nv);
    exception
        when DUP_VAL_ON_INDEX then
            dbms_output.put_line('avion nu '||na||' deja existant');
end;

create or replace procedure modif_avion(na AVION.NUAVION%type,ct AVION.CODETYPE%type,ans AVION.ANNSERV%type,er AVION.ENTREPOT%type, nv AVION.NBHVOL%type)
is 
begin
    update Avion set CODETYPE=ct,ANNSERV=ans,ENTREPOT=er,NBHVOL=nv where NUAVION=na;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Avion n existe pas');
    end if;
end;

create or replace procedure suppr_avion(na AVION.NUAVION%type)
is 
begin
    delete from Avion where nuavion=na;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Avion n existe pas!');
    end if;
end;

-- Affectation

create or replace procedure ajout_affectation(nv AFFECTATION.NUVOL%type, dav AFFECTATION.DATEVOL%type, np AFFECTATION.NUPILOTE%type, na AFFECTATION.NUAVION%type ,nbrp AFFECTATION.NBRPASSAGERS%type)
is
begin
    insert into Affectation values (nv,dav,np,na,nbrp);
    exception
        when DUP_VAL_ON_INDEX then
            dbms_output.put_line('Affectation deja existant');
end;

create or replace procedure suppr_affectation(nv AFFECTATION.NUVOL%type,dav AFFECTATION.DATEVOL%type)
is 
begin
    delete from Affectation where (nuvol = nv) and (datevol = dav);
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Affectation n existe pas!');
    end if;
end;

-- Vol

create or replace procedure ajout_vol(nv VOL.NUVOL%type, vd VOL.VILLEDEP%type, va VOL.VILLEARR%type, dh VOL.DEPHEURE%type ,dm VOL.DEPMIN%type,ah VOL.ARRHEURE%type, am VOL.ARRMIN%type)
is
begin
    if(dh > ah) then
        insert into Vol values (nv,vd,va,dh,dm,ah,am,1);
    else
        insert into Vol values (nv,vd,va,dh,dm,ah,am,0);
    end if;
    exception
        when DUP_VAL_ON_INDEX then
            dbms_output.put_line('Vol deja existant');
end;

create or replace procedure modif_vol(nv VOL.NUVOL%type, vd VOL.VILLEDEP%type, va VOL.VILLEARR%type, dh VOL.DEPHEURE%type ,dm VOL.DEPMIN%type,ah VOL.ARRHEURE%type, am VOL.ARRMIN%type)
is 
begin
    update Vol set VILLEDEP=vd,VILLEARR=va,DEPHEURE=dh,DEPMIN=dm,ARRHEURE=ah,ARRMIN=am where NUVOL=nv;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Vol n existe pas!!');
    end if;
end;

create or replace procedure suppr_vol(nv VOL.NUVOL%type)
is 
begin
    delete from Vol where nuvol = nv;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Vol n existe pas!!');
    end if;
end;

-- Pilote

create or replace procedure ajout_pilote(np PILOTE.NUPILOTE%type,nom PILOTE.NOM%type,adr PILOTE.ADRESS%type,sal PILOTE.SALAIRE,com PILOTE.COMM%type,de PILOTE.DATEMBAUCHE%type)
is
begin
    insert into Pilote values (np,nom,adr,sal,com,de);
    exception
        when DUP_VAL_ON_INDEX then
            dbms_output.put_line('Pilote deja existant');
end;

create or replace procedure modif_pilote(np PILOTE.NUPILOTE%type,nom PILOTE.NOM%type,adr PILOTE.ADRESS%type,sal PILOTE.SALAIRE,com PILOTE.COMM%type,de PILOTE.DATEMBAUCHE%type)
is 
begin
    update Pilote set NOM=nom,ADRESS=adr,SALAIRE=sal,COMM=com,DATEMBAUCHE=de where NUPILOTE=np;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Pilote n existe pas!!');
    end if;
end;

create or replace procedure suppr_pilote(np PILOTE.NUPILOTE%type)
is 
begin
    delete from Pilote where NUPILOTE = np;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Pilote n existe pas!!');
    end if;
end;


-- Appareil


create or replace procedure ajout_appareil(ct APPAREIL.CODETYPE%type ,fam APPAREIL.FAMILLE,nbrp APPAREIL.NBRPLACES%type)
is
begin
    insert into Appareil values (ct,fam,nbrp);
    exception
        when DUP_VAL_ON_INDEX then
            dbms_output.put_line('Appareil deja existant');
end;

create or replace procedure modif_appareil(ct APPAREIL.CODETYPE%type ,fam APPAREIL.FAMILLE,nbrp APPAREIL.NBRPLACES%type)
is 
begin
    update Appareil set FAMILLE=fam,NBRPLACES=nbrp where CODETYPE=ct;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Appareil n existe pas!!');
    end if;
end;

create or replace procedure suppr_appareil(ct APPAREIL.CODETYPE%type)
is 
begin
    delete from Appareil where CODETYPE = ct;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Appareil n existe pas!!');
    end if;
end;


-- Audit_Avion


create or replace procedure ajout_audit( numav Avion.nuavion%type )
is
begin
    insert into Audit_Avion values (numav,to_date(TO_CHAR(SYSDATE, 'dd-mm-yyyy'),'dd-mm-yyyy'),TO_CHAR(SYSDATE, 'hh24:mi'),0);
    exception
        when DUP_VAL_ON_INDEX then
            dbms_output.put_line('avion nu '|| numav || ' deja existant');
end;


create or replace procedure modif_audit( numav Avion.nuavion%type )
is
begin
    update Audit_Avion set der_maj_date=to_date(TO_CHAR(SYSDATE, 'dd-mm-yyyy'),'dd-mm-yyyy'),der_maj_heure=TO_CHAR(SYSDATE, 'hh24:mi'),nbr_modif=nbr_modif+1 where nuavion=numav;
    if (sql%rowcount = 0) then
                DBMS_OUTPUT.PUT_LINE('avion n existe pas!!');
    end if;
end;


create or replace procedure suppr_audit(numav Avion.nuavion%type)
is 
begin
    delete from Audit_Avion where nuavion = numav;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Appareil n existe pas!!');
    end if;
end;


-- LogAvion

create or replace procedure suppr_logavion(io APPAREIL.CODETYPE%type)
is 
begin
    delete from Appareil where CODETYPE = ct;
    if (sql%rowcount = 0) then
        DBMS_OUTPUT.PUT_LINE('Appareil n existe pas!!');
    end if;
end;