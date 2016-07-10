create table Audit_Avion (nuavion number,der_maj_date date not null,der_maj_heure varchar(5) not null,nbr_modif number not null,
constraint pk_aud_av primary key (nuavion),
constraint fk_av_aud foreign key (nuavion) references Avion (nuavion));

commit;