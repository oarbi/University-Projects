package com.project.util;

import org.hibernate.HibernateException;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.hibernate.service.ServiceRegistry;
import org.hibernate.service.ServiceRegistryBuilder;

public class HibernateUtil {

	public static SessionFactory sessionFactory;
	private static ServiceRegistry serviceRegistry;
	public static String CONFIG_FILE_LOCATION = "hibernate.cfg.xml";
	static 
	{
		try
		{
			Configuration configuration = new Configuration().configure();;
			serviceRegistry = new ServiceRegistryBuilder().applySettings(configuration.getProperties()). buildServiceRegistry();
			sessionFactory = configuration.buildSessionFactory(serviceRegistry);
		} 
		catch (HibernateException ex) 
		{
			System.err.println("Initial SessionFactory creation failed." + ex);
			throw new ExceptionInInitializerError(ex);
		}
	}
/*	public static SessionFactory getSessionFactory()
	{
		try
		{
			return sessionFactory;
		}
		catch (Exception e)
		{
			System.err.println("Could not locate SessionFactory "+ e);
			throw new IllegalStateException("Could not locate SessionFactory");
		}
	}*/
}
