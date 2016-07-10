create or replace function duree(nv in VOL.NUVOL%type)
return varchar2
is
    ddep DECAL.DECAL%type;
    sdep DECAL.SIGNDECAL%type;
    hdep VOL.DEPHEURE%type;
    mdep VOL.DEPMIN%type;
    darr DECAL.DECAL%type;
    sarr DECAL.SIGNDECAL%type;
    harr VOL.ARRHEURE%type;
    marr VOL.ARRMIN%type;
    jarr VOL.JOURARR%type;
    mindep number;
    minarr number;
    dmindep number;
    dminarr number;
    dr number;
begin
    select decal,signdecal into ddep,sdep from Decal,Vol where (nuvol=nv)and(villedep = ville);
    select decal,signdecal into darr,sarr from Decal,Vol where (nuvol=nv)and(villearr = ville);
    select jourarr into jarr from Vol where (nuvol=nv);
    select depheure into hdep from Vol where nuvol = nv;
    select arrheure into harr from Vol where nuvol = nv;
    select depmin into mdep from Vol where nuvol = nv;
    select arrmin into marr from Vol where nuvol = nv;
    mindep := hdep*60 + mdep;
    minarr := harr*60 + marr;
    if(sdep like '-') then
        dmindep := -(to_number(to_char(to_date(ddep,'hh:mi'),'hh'))*60 + to_number(to_char(to_date(ddep,'hh:mi'),'mi')));
    else dmindep := to_number(to_char(to_date(ddep,'hh:mi'),'hh'))*60 + to_number(to_char(to_date(ddep,'hh:mi'),'mi'));
    end if;
    if(sarr like '-') then
        dminarr := -(to_number(to_char(to_date(darr,'hh:mi'),'hh'))*60 + to_number(to_char(to_date(darr,'hh:mi'),'mi')));
    else dminarr := to_number(to_char(to_date(darr,'hh:mi'),'hh'))*60 + to_number(to_char(to_date(darr,'hh:mi'),'mi'));
    end if;
    if(jarr = 0) then
        dr :=(minarr-dminarr) - (mindep-dmindep);
    else dr :=((24*60)+minarr-dminarr) - (mindep-dmindep);
    end if;
    if((mod(dr,60))<10) then
        return to_char((trunc(dr/60))||':0'||(mod(dr,60)));
    else return to_char((trunc(dr/60))||':'||(mod(dr,60)));
    end if;
end;


begin
    dbms_output.put_line(duree('AF8810'));
end;