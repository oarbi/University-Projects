create or replace procedure cherch_pil(nv AFFECTATION.NUVOL%type,davo AFFECTATION.DATEVOL%type)
is
    hd VOL.DEPHEURE%type;
    nup PILOTE.NUPILOTE%type;
    nop PILOTE.NOM%type;
    cursor curpil
    is
        select distinct pl.nupilote,pl.nom from Affectation af,Pilote pl where (pl.nupilote not in (select distinct nupilote from affectation));
    cursor curpild(dvol AFFECTATION.DATEVOL%type,hvol VOL.DEPHEURE%type)
    is
        select distinct af.nupilote,pl.nom from Affectation af,Pilote pl,Vol vl where (af.nupilote=pl.nupilote) and (af.nuvol = vl.nuvol) and ((af.datevol != dvol)or(vl.depheure != hvol));
begin
    select depheure into hd from Vol where (nv = nuvol);
    open curpil;
    loop
        fetch curpil into nup,nop;
        exit when curpil%notfound;
        dbms_output.put_line(nup||' '||nop);
    end loop;
    close curpil;
    open curpild(davo,hd);
    loop
        fetch curpild into nup,nop;
        exit when curpild%notfound;
        dbms_output.put_line(nup||' '||nop);
    end loop;
    close curpild;
end;


create or replace procedure cherch_av(nv AFFECTATION.NUVOL%type,davo AFFECTATION.DATEVOL%type,nbrp AFFECTATION.NBRPASSAGERS%type)
is
    hd VOL.DEPHEURE%type;
    nuav AVION.NUAVION%type;
    fav APPAREIL.FAMILLE%type;
    cursor curav(nbp AFFECTATION.NBRPASSAGERS%type)
    is
        select distinct av.nuavion,ap.famille from Affectation af,Avion av,Appareil ap where (ap.codetype = av.codetype)and(ap.nbrplaces >=nbp)and(av.nuavion not in (select distinct nuavion from affectation));
    cursor curavd(dvol AFFECTATION.DATEVOL%type,hvol VOL.DEPHEURE%type,nbp AFFECTATION.NBRPASSAGERS%type)
    is
        select distinct af.nuavion,ap.famille from Affectation af,Avion av,Vol vl,Appareil ap where(af.nuavion=av.nuavion)and(ap.codetype = av.codetype)and(ap.nbrplaces >=nbp)and(af.nuvol = vl.nuvol)and((af.datevol != dvol)or(vl.depheure != hvol));
begin
    select depheure into hd from Vol where (nv = nuvol);
    open curav(nbrp);
    loop
        fetch curav into nuav,fav;
        exit when curav%notfound;
        dbms_output.put_line(nuav||' '||fav);
    end loop;
    close curav;
    open curavd(davo,hd,nbrp);
    loop
        fetch curavd into nuav,fav;
        exit when curavd%notfound;
        dbms_output.put_line(nuav||' '||fav);
    end loop;
    close curavd;
end;


create or replace procedure cherch_pil_av(nv AFFECTATION.NUVOL%type,davo AFFECTATION.DATEVOL%type,nbrp AFFECTATION.NBRPASSAGERS%type)
is
begin
    dbms_output.put_line('Les Pilotes disponibles sont : ');
    cherch_pil(nv,davo);
    dbms_output.put_line('Les Avions disponible sont : ');
    cherch_av(nv,davo,nbrp);
end;

begin
    cherch_pil_av('JW201',to_date('01/03/1994','dd-mm-yyyy'),451);
end;
