CREATE DATABASE  IF NOT EXISTS `mynorthwind`  /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `mynorthwind`;
-- MySQL dump 10.13  Distrib 8.0.33, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: movedb
-- ------------------------------------------------------
-- Server version	8.0.33

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `categories`
--

DROP TABLE IF EXISTS `categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `categories` (
  `CategoryID` int NOT NULL AUTO_INCREMENT,
  `CategoryName` varchar(15) NOT NULL,
  `Description` longtext,
  PRIMARY KEY (`CategoryID`),
  UNIQUE KEY `CategoryName` (`CategoryName`)
) ENGINE=InnoDB AUTO_INCREMENT=9 ;-- DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `categories`
--

LOCK TABLES `categories` WRITE;
/*!40000 ALTER TABLE `categories` DISABLE KEYS */;
INSERT INTO `categories` VALUES (1,'Beverages','Soft drinks, coffees, teas, beers, and ales'),(2,'Condiments','Sweet and savory sauces, relishes, spreads, and seasonings'),(3,'Confections','Desserts, candies, and sweet breads'),(4,'Dairy Products','Cheeses'),(5,'Grains/Cereals','Breads, crackers, pasta, and cereal'),(6,'Meat/Poultry','Prepared meats'),(7,'Produce','Dried fruit and bean curd'),(8,'Seafood','Seaweed and fish');
/*!40000 ALTER TABLE `categories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customers`
--

DROP TABLE IF EXISTS `customers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customers` (
  `CustomerID` varchar(5) NOT NULL,
  `CompanyName` varchar(40) NOT NULL,
  `ContactName` varchar(30) DEFAULT NULL,
  `ContactTitle` varchar(30) DEFAULT NULL,
  `Address` varchar(60) DEFAULT NULL,
  `City` varchar(15) DEFAULT NULL,
  `Region` varchar(15) DEFAULT NULL,
  `PostalCode` varchar(10) DEFAULT NULL,
  `Country` varchar(15) DEFAULT NULL,
  `Phone` varchar(24) DEFAULT NULL,
  `Fax` varchar(24) DEFAULT NULL,
  PRIMARY KEY (`CustomerID`),
  KEY `City` (`City`),
  KEY `CompanyName` (`CompanyName`),
  KEY `PostalCode` (`PostalCode`),
  KEY `Region` (`Region`)
) ENGINE=InnoDB; -- DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customers`
--

LOCK TABLES `customers` WRITE;
/*!40000 ALTER TABLE `customers` DISABLE KEYS */;
INSERT INTO `customers` VALUES ('ALFKI','Alfreds Futterkiste','Maria Anders','Sales Representative','Obere Str. 57','Berlin',NULL,'12209','Germany','030-0074321','030-0076545'),('ANATR','Ana Trujillo Emparedados y helados','Ana Trujillo','Owner','Avda. de la Constituciףn 2222','Mיxico D.F.',NULL,'05021','Mexico','(5) 555-4729','(5) 555-3745'),('ANTON','Antonio Moreno Taquerםa','Antonio Moreno','Owner','Mataderos  2312','Mיxico D.F.',NULL,'05023','Mexico','(5) 555-3932',NULL),('AROUT','Around the Horn','Thomas Hardy','Sales Representative','120 Hanover Sq.','London',NULL,'WA1 1DP','UK','(171) 555-7788','(171) 555-6750'),('BERGS','Berglunds snabbkצp','Christina Berglund','Order Administrator','Berguvsvהgen  8','Luleו',NULL,'S-958 22','Sweden','0921-12 34 65','0921-12 34 67'),('BLAUS','Blauer See Delikatessen','Hanna Moos','Sales Representative','Forsterstr. 57','Mannheim',NULL,'68306','Germany','0621-08460','0621-08924'),('BLONP','Blondel pטre et fils','Frיdיrique Citeaux','Marketing Manager','24, place Klיber','Strasbourg',NULL,'67000','France','88.60.15.31','88.60.15.32'),('BOLID','Bףlido Comidas preparadas','Martםn Sommer','Owner','C/ Araquil, 67','Madrid',NULL,'28023','Spain','(91) 555 22 82','(91) 555 91 99'),('BONAP','Bon app\'','Laurence Lebihan','Owner','12, rue des Bouchers','Marseille',NULL,'13008','France','91.24.45.40','91.24.45.41'),('BOTTM','Bottom-Dollar Markets','Elizabeth Lincoln','Accounting Manager','23 Tsawassen Blvd.','Tsawassen','BC','T2F 8M4','Canada','(604) 555-4729','(604) 555-3745'),('BSBEV','B\'s Beverages','Victoria Ashworth','Sales Representative','Fauntleroy Circus','London',NULL,'EC2 5NT','UK','(171) 555-1212',NULL),('CACTU','Cactus Comidas para llevar','Patricio Simpson','Sales Agent','Cerrito 333','Buenos Aires',NULL,'1010','Argentina','(1) 135-5555','(1) 135-4892'),('CENTC','Centro comercial Moctezuma','Francisco Chang','Marketing Manager','Sierras de Granada 9993','Mיxico D.F.',NULL,'05022','Mexico','(5) 555-3392','(5) 555-7293'),('CHOPS','Chop-suey Chinese','Yang Wang','Owner','Hauptstr. 29','Bern',NULL,'3012','Switzerland','0452-076545',NULL),('COMMI','Comיrcio Mineiro','Pedro Afonso','Sales Associate','Av. dos Lusםadas, 23','Sדo Paulo','SP','05432-043','Brazil','(11) 555-7647',NULL),('CONSH','Consolidated Holdings','Elizabeth Brown','Sales Representative','Berkeley Gardens\r\n12  Brewery ','London',NULL,'WX1 6LT','UK','(171) 555-2282','(171) 555-9199'),('DRACD','Drachenblut Delikatessen','Sven Ottlieb','Order Administrator','Walserweg 21','Aachen',NULL,'52066','Germany','0241-039123','0241-059428'),('DUMON','Du monde entier','Janine Labrune','Owner','67, rue des Cinquante Otages','Nantes',NULL,'44000','France','40.67.88.88','40.67.89.89'),('EASTC','Eastern Connection','Ann Devon','Sales Agent','35 King George','London',NULL,'WX3 6FW','UK','(171) 555-0297','(171) 555-3373'),('ERNSH','Ernst Handel','Roland Mendel','Sales Manager','Kirchgasse 6','Graz',NULL,'8010','Austria','7675-3425','7675-3426'),('FAMIA','Familia Arquibaldo','Aria Cruz','Marketing Assistant','Rua Orףs, 92','Sדo Paulo','SP','05442-030','Brazil','(11) 555-9857',NULL),('FOLIG','Folies gourmandes','Martine Rancי','Assistant Sales Agent','184, chaussיe de Tournai','Lille',NULL,'59000','France','20.16.10.16','20.16.10.17'),('FOLKO','Folk och fה HB','Maria Larsson','Owner','ֵkergatan 24','Brהcke',NULL,'S-844 67','Sweden','0695-34 67 21',NULL),('FRANK','Frankenversand','Peter Franken','Marketing Manager','Berliner Platz 43','Mnchen',NULL,'80805','Germany','089-0877310','089-0877451'),('FRANR','France restauration','Carine Schmitt','Marketing Manager','54, rue Royale','Nantes',NULL,'44000','France','40.32.21.21','40.32.21.20'),('FRANS','Franchi S.p.A.','Paolo Accorti','Sales Representative','Via Monte Bianco 34','Torino',NULL,'10100','Italy','011-4988260','011-4988261'),('FURIB','Furia Bacalhau e Frutos do Mar','Lino Rodriguez ','Sales Manager','Jardim das rosas n. 32','Lisboa',NULL,'1675','Portugal','(1) 354-2534','(1) 354-2535'),('GALED','Galerםa del gastrףnomo','Eduardo Saavedra','Marketing Manager','Rambla de Cataluסa, 23','Barcelona',NULL,'08022','Spain','(93) 203 4560','(93) 203 4561'),('GODOS','Godos Cocina Tםpica','Josי Pedro Freyre','Sales Manager','C/ Romero, 33','Sevilla',NULL,'41101','Spain','(95) 555 82 82',NULL),('GOURL','Gourmet Lanchonetes','Andrי Fonseca','Sales Associate','Av. Brasil, 442','Campinas','SP','04876-786','Brazil','(11) 555-9482',NULL),('GREAL','Great Lakes Food Market','Howard Snyder','Marketing Manager','2732 Baker Blvd.','Eugene','OR','97403','USA','(503) 555-7555',NULL),('GROSR','GROSELLA-Restaurante','Manuel Pereira','Owner','5× Ave. Los Palos Grandes','Caracas','DF','1081','Venezuela','(2) 283-2951','(2) 283-3397'),('HANAR','Hanari Carnes','Mario Pontes','Accounting Manager','Rua do Paחo, 67','Rio de Janeiro','RJ','05454-876','Brazil','(21) 555-0091','(21) 555-8765'),('HILAA','HILARI׃N-Abastos','Carlos Hernבndez','Sales Representative','Carrera 22 con Ave. Carlos Soublette #8-35','San Cristףbal','Tבchira','5022','Venezuela','(5) 555-1340','(5) 555-1948'),('HUNGC','Hungry Coyote Import Store','Yoshi Latimer','Sales Representative','City Center Plaza\r\n516 Main St.','Elgin','OR','97827','USA','(503) 555-6874','(503) 555-2376'),('HUNGO','Hungry Owl All-Night Grocers','Patricia McKenna','Sales Associate','8 Johnstown Road','Cork','Co. Cork',NULL,'Ireland','2967 542','2967 3333'),('ISLAT','Island Trading','Helen Bennett','Marketing Manager','Garden House\r\nCrowther Way','Cowes','Isle of Wight','PO31 7PJ','UK','(198) 555-8888',NULL),('KOENE','Kצniglich Essen','Philip Cramer','Sales Associate','Maubelstr. 90','Brandenburg',NULL,'14776','Germany','0555-09876',NULL),('LACOR','La corne d\'abondance','Daniel Tonini','Sales Representative','67, avenue de l\'Europe','Versailles',NULL,'78000','France','30.59.84.10','30.59.85.11'),('LAMAI','La maison d\'Asie','Annette Roulet','Sales Manager','1 rue Alsace-Lorraine','Toulouse',NULL,'31000','France','61.77.61.10','61.77.61.11'),('LAUGB','Laughing Bacchus Wine Cellars','Yoshi Tannamuri','Marketing Assistant','1900 Oak St.','Vancouver','BC','V3F 2K1','Canada','(604) 555-3392','(604) 555-7293'),('LAZYK','Lazy K Kountry Store','John Steel','Marketing Manager','12 Orchestra Terrace','Walla Walla','WA','99362','USA','(509) 555-7969','(509) 555-6221'),('LEHMS','Lehmanns Marktstand','Renate Messner','Sales Representative','Magazinweg 7','Frankfurt a.M. ',NULL,'60528','Germany','069-0245984','069-0245874'),('LETSS','Let\'s Stop N Shop','Jaime Yorres','Owner','87 Polk St.\r\nSuite 5','San Francisco','CA','94117','USA','(415) 555-5938',NULL),('LILAS','LILA-Supermercado','Carlos Gonzבlez','Accounting Manager','Carrera 52 con Ave. Bolםvar #65-98 Llano Largo','Barquisimeto','Lara','3508','Venezuela','(9) 331-6954','(9) 331-7256'),('LINOD','LINO-Delicateses','Felipe Izquierdo','Owner','Ave. 5 de Mayo Porlamar','I. de Margarita','Nueva Esparta','4980','Venezuela','(8) 34-56-12','(8) 34-93-93'),('LONEP','Lonesome Pine Restaurant','Fran Wilson','Sales Manager','89 Chiaroscuro Rd.','Portland','OR','97219','USA','(503) 555-9573','(503) 555-9646'),('MAGAA','Magazzini Alimentari Riuniti','Giovanni Rovelli','Marketing Manager','Via Ludovico il Moro 22','Bergamo',NULL,'24100','Italy','035-640230','035-640231'),('MAISD','Maison Dewey','Catherine Dewey','Sales Agent','Rue Joseph-Bens 532','Bruxelles',NULL,'B-1180','Belgium','(02) 201 24 67','(02) 201 24 68'),('MEREP','Mטre Paillarde','Jean Fresniטre','Marketing Assistant','43 rue St. Laurent','Montrיal','Quיbec','H1J 1C3','Canada','(514) 555-8054','(514) 555-8055'),('MORGK','Morgenstern Gesundkost','Alexander Feuer','Marketing Assistant','Heerstr. 22','Leipzig',NULL,'04179','Germany','0342-023176',NULL),('NORTS','North/South','Simon Crowther','Sales Associate','South House\r\n300 Queensbridge','London',NULL,'SW7 1RZ','UK','(171) 555-7733','(171) 555-2530'),('OCEAN','Ocיano Atlבntico Ltda.','Yvonne Moncada','Sales Agent','Ing. Gustavo Moncada 8585\r\nPiso 20-A','Buenos Aires',NULL,'1010','Argentina','(1) 135-5333','(1) 135-5535'),('OLDWO','Old World Delicatessen','Rene Phillips','Sales Representative','2743 Bering St.','Anchorage','AK','99508','USA','(907) 555-7584','(907) 555-2880'),('OTTIK','Ottilies Kהseladen','Henriette Pfalzheim','Owner','Mehrheimerstr. 369','Kצln',NULL,'50739','Germany','0221-0644327','0221-0765721'),('PERIC','Pericles Comidas clבsicas','Guillermo Fernבndez','Sales Representative','Calle Dr. Jorge Cash 321','Mיxico D.F.',NULL,'05033','Mexico','(5) 552-3745','(5) 545-3745'),('PICCO','Piccolo und mehr','Georg Pipps','Sales Manager','Geislweg 14','Salzburg',NULL,'5020','Austria','6562-9722','6562-9723'),('PRINI','Princesa Isabel Vinhos','Isabel de Castro','Sales Representative','Estrada da saתde n. 58','Lisboa',NULL,'1756','Portugal','(1) 356-5634',NULL),('QUEDE','Que Delםcia','Bernardo Batista','Accounting Manager','Rua da Panificadora, 12','Rio de Janeiro','RJ','02389-673','Brazil','(21) 555-4252','(21) 555-4545'),('QUEEN','Queen Cozinha','Lתcia Carvalho','Marketing Assistant','Alameda dos Canאrios, 891','Sדo Paulo','SP','05487-020','Brazil','(11) 555-1189',NULL),('QUICK','QUICK-Stop','Horst Kloss','Accounting Manager','Taucherstrae 10','Cunewalde',NULL,'01307','Germany','0372-035188',NULL),('RANCH','Rancho grande','Sergio Gutiיrrez','Sales Representative','Av. del Libertador 900','Buenos Aires',NULL,'1010','Argentina','(1) 123-5555','(1) 123-5556'),('RATTC','Rattlesnake Canyon Grocery','Paula Wilson','Assistant Sales Representative','2817 Milton Dr.','Albuquerque','NM','87110','USA','(505) 555-5939','(505) 555-3620'),('REGGC','Reggiani Caseifici','Maurizio Moroni','Sales Associate','Strada Provinciale 124','Reggio Emilia',NULL,'42100','Italy','0522-556721','0522-556722'),('RICAR','Ricardo Adocicados','Janete Limeira','Assistant Sales Agent','Av. Copacabana, 267','Rio de Janeiro','RJ','02389-890','Brazil','(21) 555-3412',NULL),('RICSU','Richter Supermarkt','Michael Holz','Sales Manager','Grenzacherweg 237','Genטve',NULL,'1203','Switzerland','0897-034214',NULL),('ROMEY','Romero y tomillo','Alejandra Camino','Accounting Manager','Gran Vםa, 1','Madrid',NULL,'28001','Spain','(91) 745 6200','(91) 745 6210'),('SANTG','Santי Gourmet','Jonas Bergulfsen','Owner','Erling Skakkes gate 78','Stavern',NULL,'4110','Norway','07-98 92 35','07-98 92 47'),('SAVEA','Save-a-lot Markets','Jose Pavarotti','Sales Representative','187 Suffolk Ln.','Boise','ID','83720','USA','(208) 555-8097',NULL),('SEVES','Seven Seas Imports','Hari Kumar','Sales Manager','90 Wadhurst Rd.','London',NULL,'OX15 4NB','UK','(171) 555-1717','(171) 555-5646'),('SIMOB','Simons bistro','Jytte Petersen','Owner','Vinbזltet 34','Kרbenhavn',NULL,'1734','Denmark','31 12 34 56','31 13 35 57'),('SPECD','Spיcialitיs du monde','Dominique Perrier','Marketing Manager','25, rue Lauriston','Paris',NULL,'75016','France','(1) 47.55.60.10','(1) 47.55.60.20'),('SPLIR','Split Rail Beer & Ale','Art Braunschweiger','Sales Manager','P.O. Box 555','Lander','WY','82520','USA','(307) 555-4680','(307) 555-6525'),('SUPRD','Suprךmes dיlices','Pascale Cartrain','Accounting Manager','Boulevard Tirou, 255','Charleroi',NULL,'B-6000','Belgium','(071) 23 67 22 20','(071) 23 67 22 21'),('THEBI','The Big Cheese','Liz Nixon','Marketing Manager','89 Jefferson Way\r\nSuite 2','Portland','OR','97201','USA','(503) 555-3612',NULL),('THECR','The Cracker Box','Liu Wong','Marketing Assistant','55 Grizzly Peak Rd.','Butte','MT','59801','USA','(406) 555-5834','(406) 555-8083'),('TOMSP','Toms Spezialitהten','Karin Josephs','Marketing Manager','Luisenstr. 48','Mnster',NULL,'44087','Germany','0251-031259','0251-035695'),('TORTU','Tortuga Restaurante','Miguel Angel Paolino','Owner','Avda. Azteca 123','Mיxico D.F.',NULL,'05033','Mexico','(5) 555-2933',NULL),('TRADH','Tradiחדo Hipermercados','Anabela Domingues','Sales Representative','Av. Inךs de Castro, 414','Sדo Paulo','SP','05634-030','Brazil','(11) 555-2167','(11) 555-2168'),('TRAIH','Trail\'s Head Gourmet Provisioners','Helvetius Nagy','Sales Associate','722 DaVinci Blvd.','Kirkland','WA','98034','USA','(206) 555-8257','(206) 555-2174'),('VAFFE','Vaffeljernet','Palle Ibsen','Sales Manager','Smagslרget 45','ֵrhus',NULL,'8200','Denmark','86 21 32 43','86 22 33 44'),('VICTE','Victuailles en stock','Mary Saveley','Sales Agent','2, rue du Commerce','Lyon',NULL,'69004','France','78.32.54.86','78.32.54.87'),('VINET','Vins et alcools Chevalier','Paul Henriot','Accounting Manager','59 rue de l\'Abbaye','Reims',NULL,'51100','France','26.47.15.10','26.47.15.11'),('WANDK','Die Wandernde Kuh','Rita Mller','Sales Representative','Adenauerallee 900','Stuttgart',NULL,'70563','Germany','0711-020361','0711-035428'),('WARTH','Wartian Herkku','Pirkko Koskitalo','Accounting Manager','Torikatu 38','Oulu',NULL,'90110','Finland','981-443655','981-443655'),('WELLI','Wellington Importadora','Paula Parente','Sales Manager','Rua do Mercado, 12','Resende','SP','08737-363','Brazil','(14) 555-8122',NULL),('WHITC','White Clover Markets','Karl Jablonski','Owner','305 - 14th Ave. S.\r\nSuite 3B','Seattle','WA','98128','USA','(206) 555-4112','(206) 555-4115'),('WILMK','Wilman Kala','Matti Karttunen','Owner/Marketing Assistant','Keskuskatu 45','Helsinki',NULL,'21240','Finland','90-224 8858','90-224 8858'),('WOLZA','Wolski  Zajazd','Zbyszek Piestrzeniewicz','Owner','ul. Filtrowa 68','Warszawa',NULL,'01-012','Poland','(26) 642-7012','(26) 642-7012');
/*!40000 ALTER TABLE `customers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employees`
--

DROP TABLE IF EXISTS `employees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employees` (
  `EmployeeID` int NOT NULL AUTO_INCREMENT,
  `LastName` varchar(20) NOT NULL,
  `FirstName` varchar(10) NOT NULL,
  `Title` varchar(30) DEFAULT NULL,
  `BirthDate` date DEFAULT NULL,
  `Address` varchar(60) DEFAULT NULL,
  `City` varchar(15) DEFAULT NULL,
  `Region` varchar(15) DEFAULT NULL,
  `PostalCode` varchar(10) DEFAULT NULL,
  `Country` varchar(15) DEFAULT NULL,
  `HomePhone` varchar(24) DEFAULT NULL,
  `Salary` int DEFAULT NULL,
  `DepartmentID` int DEFAULT NULL,
  PRIMARY KEY (`EmployeeID`),
  KEY `LastName` (`LastName`),
  KEY `PostalCode` (`PostalCode`)
) ENGINE=InnoDB AUTO_INCREMENT=10 ; -- DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employees`
--

LOCK TABLES `employees` WRITE;
/*!40000 ALTER TABLE `employees` DISABLE KEYS */;
INSERT INTO `employees` VALUES (1,'Davolio','Nancy','Sales Representative','1948-12-08 00:00:00','507 - 20th Ave. E.\r\nApt. 2A','Seattle','WA','98122','USA','(206) 555-9857',13000,1),(2,'Fuller','Andrew','Vice President, Sales','1952-02-19 00:00:00','908 W. Capital Way','Tacoma','WA','98401','USA','(206) 555-9482',4300,2),(3,'Leverling','Janet','Sales Representative','1963-08-30 00:00:00','722 Moss Bay Blvd.','Kirkland','WA','98033','USA','(206) 555-3412',5200,2),(4,'Peacock','Margaret','Sales Representative','1937-09-19 00:00:00','4110 Old Redmond Rd.','Redmond','WA','98052','USA','(206) 555-8122',6700,2),(5,'Buchanan','Steven','Sales Manager','1955-03-04 00:00:00','14 Garrett Hill','London',NULL,'SW1 8JR','UK','(71) 555-4848',8200,2),(6,'Suyama','Michael','Sales Representative','1963-07-02 00:00:00','Coventry House\r\nMiner Rd.','London',NULL,'EC2 7JR','UK','(71) 555-7773',16500,3),(7,'King','Robert','Sales Representative','1960-05-29 00:00:00','Edgeham Hollow\r\nWinchester Way','London',NULL,'RG1 9SP','UK','(71) 555-5598',5200,1),(8,'Callahan','Laura','Inside Sales Coordinator','1958-01-09 00:00:00','4726 - 11th Ave. N.E.','Seattle','WA','98105','USA','(206) 555-1189',12500,2),(9,'Dodsworth','Anne','Sales Representative','1966-01-27 00:00:00','7 Houndstooth Rd.','London',NULL,'WG2 7LT','UK','(71) 555-4444',4000,1);
/*!40000 ALTER TABLE `employees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `suppliers`
--

DROP TABLE IF EXISTS `suppliers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `suppliers` (
  `SupplierID` int NOT NULL AUTO_INCREMENT,
  `CompanyName` varchar(40) NOT NULL,
  `ContactName` varchar(30) DEFAULT NULL,
  `ContactTitle` varchar(30) DEFAULT NULL,
  `Address` varchar(60) DEFAULT NULL,
  `City` varchar(15) DEFAULT NULL,
  `Region` varchar(15) DEFAULT NULL,
  `PostalCode` varchar(10) DEFAULT NULL,
  `Country` varchar(15) DEFAULT NULL,
  `Phone` varchar(24) DEFAULT NULL,
  `Fax` varchar(24) DEFAULT NULL,
  `HomePage` longtext,
  PRIMARY KEY (`SupplierID`),
  KEY `CompanyName` (`CompanyName`),
  KEY `PostalCode` (`PostalCode`)
) ENGINE=InnoDB AUTO_INCREMENT=30; -- DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `suppliers`
--

LOCK TABLES `suppliers` WRITE;
/*!40000 ALTER TABLE `suppliers` DISABLE KEYS */;
INSERT INTO `suppliers` VALUES (1,'Exotic Liquids','Charlotte Cooper','Purchasing Manager','49 Gilbert St.','London',NULL,'EC1 4SD','UK','(171) 555-2222',NULL,NULL),(2,'New Orleans Cajun Delights','Shelley Burke','Order Administrator','P.O. Box 78934','New Orleans','LA','70117','USA','(100) 555-4822',NULL,'#CAJUN.HTM#'),(3,'Grandma Kelly\'s Homestead','Regina Murphy','Sales Representative','707 Oxford Rd.','Ann Arbor','MI','48104','USA','(313) 555-5735','(313) 555-3349',NULL),(4,'Tokyo Traders','Yoshi Nagase','Marketing Manager','9-8 Sekimai\r\nMusashino-shi','Tokyo',NULL,'100','Japan','(03) 3555-5011',NULL,NULL),(5,'Cooperativa de Quesos \'Las Cabras\'','Antonio del Valle Saavedra ','Export Administrator','Calle del Rosal 4','Oviedo','Asturias','33007','Spain','(98) 598 76 54',NULL,NULL),(6,'Mayumi\'s','Mayumi Ohno','Marketing Representative','92 Setsuko\r\nChuo-ku','Osaka',NULL,'545','Japan','(06) 431-7877',NULL,'Mayumi\'s (on the World Wide Web)#http://www.microsoft.com/accessdev/sampleapps/mayumi.htm#'),(7,'Pavlova, Ltd.','Ian Devling','Marketing Manager','74 Rose St.\r\nMoonie Ponds','Melbourne','Victoria','3058','Australia','(03) 444-2343','(03) 444-6588',NULL),(8,'Specialty Biscuits, Ltd.','Peter Wilson','Sales Representative','29 King\'s Way','Manchester',NULL,'M14 GSD','UK','(161) 555-4448',NULL,NULL),(9,'PB Knהckebrצd AB','Lars Peterson','Sales Agent','Kaloadagatan 13','Gצteborg',NULL,'S-345 67','Sweden ','031-987 65 43','031-987 65 91',NULL),(10,'Refrescos Americanas LTDA','Carlos Diaz','Marketing Manager','Av. das Americanas 12.890','Sדo Paulo',NULL,'5442','Brazil','(11) 555 4640',NULL,NULL),(11,'Heli Swaren GmbH & Co. KG','Petra Winkler','Sales Manager','Tiergartenstrae 5','Berlin',NULL,'10785','Germany','(010) 9984510',NULL,NULL),(12,'Plutzer Lebensmittelgromהrkte AG','Martin Bein','International Marketing Mgr.','Bogenallee 51','Frankfurt',NULL,'60439','Germany','(069) 992755',NULL,'Plutzer (on the World Wide Web)#http://www.microsoft.com/accessdev/sampleapps/plutzer.htm#'),(13,'Nord-Ost-Fisch Handelsgesellschaft mbH','Sven Petersen','Coordinator Foreign Markets','Frahmredder 112a','Cuxhaven',NULL,'27478','Germany','(04721) 8713','(04721) 8714',NULL),(14,'Formaggi Fortini s.r.l.','Elio Rossi','Sales Representative','Viale Dante, 75','Ravenna',NULL,'48100','Italy','(0544) 60323','(0544) 60603','#FORMAGGI.HTM#'),(15,'Norske Meierier','Beate Vileid','Marketing Manager','Hatlevegen 5','Sandvika',NULL,'1320','Norway','(0)2-953010',NULL,NULL),(16,'Bigfoot Breweries','Cheryl Saylor','Regional Account Rep.','3400 - 8th Avenue\r\nSuite 210','Bend','OR','97101','USA','(503) 555-9931',NULL,NULL),(17,'Svensk Sjצfצda AB','Michael Bjצrn','Sales Representative','Brovallavהgen 231','Stockholm',NULL,'S-123 45','Sweden','08-123 45 67',NULL,NULL),(18,'Aux joyeux ecclיsiastiques','Guylטne Nodier','Sales Manager','203, Rue des Francs-Bourgeois','Paris',NULL,'75004','France','(1) 03.83.00.68','(1) 03.83.00.62',NULL),(19,'New England Seafood Cannery','Robb Merchant','Wholesale Account Agent','Order Processing Dept.\r\n2100 Paul Revere Blvd.','Boston','MA','02134','USA','(617) 555-3267','(617) 555-3389',NULL),(20,'Leka Trading','Chandra Leka','Owner','471 Serangoon Loop, Suite #402','Singapore',NULL,'0512','Singapore','555-8787',NULL,NULL),(21,'Lyngbysild','Niels Petersen','Sales Manager','Lyngbysild\r\nFiskebakken 10','Lyngby',NULL,'2800','Denmark','43844108','43844115',NULL),(22,'Zaanse Snoepfabriek','Dirk Luchte','Accounting Manager','Verkoop\r\nRijnweg 22','Zaandam',NULL,'9999 ZZ','Netherlands','(12345) 1212','(12345) 1210',NULL),(23,'Karkki Oy','Anne Heikkonen','Product Manager','Valtakatu 12','Lappeenranta',NULL,'53120','Finland','(953) 10956',NULL,NULL),(24,'G\'day, Mate','Wendy Mackenzie','Sales Representative','170 Prince Edward Parade\r\nHunter\'s Hill','Sydney','NSW','2042','Australia','(02) 555-5914','(02) 555-4873','G\'day Mate (on the World Wide Web)#http://www.microsoft.com/accessdev/sampleapps/gdaymate.htm#'),(25,'Ma Maison','Jean-Guy Lauzon','Marketing Manager','2960 Rue St. Laurent','Montrיal','Quיbec','H1J 1C3','Canada','(514) 555-9022',NULL,NULL),(26,'Pasta Buttini s.r.l.','Giovanni Giudici','Order Administrator','Via dei Gelsomini, 153','Salerno',NULL,'84100','Italy','(089) 6547665','(089) 6547667',NULL),(27,'Escargots Nouveaux','Marie Delamare','Sales Manager','22, rue H. Voiron','Montceau',NULL,'71300','France','85.57.00.07',NULL,NULL),(28,'Gai pגturage','Eliane Noz','Sales Representative','Bat. B\r\n3, rue des Alpes','Annecy',NULL,'74000','France','38.76.98.06','38.76.98.58',NULL),(29,'Forךts d\'יrables','Chantal Goulet','Accounting Manager','148 rue Chasseur','Ste-Hyacinthe','Quיbec','J2S 7S8','Canada','(514) 555-2955','(514) 555-2921',NULL);
/*!40000 ALTER TABLE `suppliers` ENABLE KEYS */;
UNLOCK TABLES;


--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `orders` (
  `OrderID` int NOT NULL AUTO_INCREMENT,
  `CustomerID` varchar(5) DEFAULT NULL,
  `EmployeeID` int DEFAULT NULL,
  `OrderDate` datetime DEFAULT NULL,
  `RequiredDate` date DEFAULT NULL,
  PRIMARY KEY (`OrderID`),
   CONSTRAINT `fk_orders_customers`
    FOREIGN KEY (`CustomerID`)
    REFERENCES `mynorthwind`.`customers` (`CustomerID`) ON delete restrict ON update restrict,
     CONSTRAINT `fk_orders_employees`
    FOREIGN KEY (`EmployeeID`)
    REFERENCES `mynorthwind`.`employees` (`EmployeeID`) ON delete restrict ON update restrict,
  KEY `CustomerID` (`CustomerID`),
  KEY `EmployeeID` (`EmployeeID`),
  KEY `OrderDate` (`OrderDate`)
) ENGINE=InnoDB AUTO_INCREMENT=10259; -- DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (10248,'VINET',5,'1994-08-04 00:00:00','1994-09-01 00:00:00'),(10249,'TOMSP',6,'1994-08-05 00:00:00','1994-09-16 00:00:00'),(10250,'HANAR',4,'1994-08-08 00:00:00','1994-09-05 00:00:00'),(10251,'VICTE',3,'1994-08-08 00:00:00','1994-09-05 00:00:00'),(10252,'SUPRD',4,'1994-08-09 00:00:00','1994-09-06 00:00:00'),(10253,'HANAR',3,'1994-08-10 00:00:00','1994-08-24 00:00:00'),(10254,'VINET',5,'1994-08-11 00:00:00','1994-09-08 00:00:00'),(10255,'VINET',9,'1994-08-12 00:00:00','1994-09-09 00:00:00'),(10256,'WELLI',3,'1994-08-15 00:00:00','1994-09-12 00:00:00'),(10257,'HILAA',4,'1994-08-16 00:00:00','1994-09-13 00:00:00'),(10258,'ERNSH',1,'1994-08-17 00:00:00','1994-09-14 00:00:00');
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `products`
--




DROP TABLE IF EXISTS `products`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `products` (
  `ProductID` int NOT NULL AUTO_INCREMENT,
  `ProductName` varchar(40) NOT NULL,
  `SupplierID` int DEFAULT NULL,
  `CategoryID` int DEFAULT NULL,
  `QuantityPerUnit` varchar(20) DEFAULT NULL,
  `UnitPrice` decimal(19,4) DEFAULT '0.0000',
  `UnitsInStock` int DEFAULT NULL,
  `UnitsOnOrder` int DEFAULT NULL,
  `ReorderLevel` int DEFAULT NULL,
  `Discontinued` tinyint(1) DEFAULT NULL,
  `PictureUrl` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`ProductID`),
  CONSTRAINT `fk_products_Suppliers`
    FOREIGN KEY (`SupplierID`)
    REFERENCES `mynorthwind`.`suppliers` (`SupplierID`) ON delete restrict ON update restrict,
CONSTRAINT `fk_products_categories`
    FOREIGN KEY (`CategoryID`)
    REFERENCES `mynorthwind`.`categories` (`CategoryID`) ON delete restrict ON update restrict,
  KEY `CategoryID` (`CategoryID`),
  KEY `ProductName` (`ProductName`),
  KEY `SupplierID` (`SupplierID`)
) ENGINE=InnoDB AUTO_INCREMENT=79; -- DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `products`
--

LOCK TABLES `products` WRITE;
/*!40000 ALTER TABLE `products` DISABLE KEYS */;
INSERT INTO `products` VALUES (1,'Chai',1,1,'10 boxes x 20 bags',18.0000,39,0,10,0,NULL),(2,'Chang',1,1,'24 - 12 oz bottles',19.0000,17,40,25,0,NULL),(3,'Aniseed Syrup',1,2,'12 - 550 ml bottles',10.0000,13,70,25,0,NULL),(4,'Chef Anton\'s Cajun Seasoning',2,2,'48 - 6 oz jars',22.0000,53,0,0,0,NULL),(5,'Chef Anton\'s Gumbo Mix',2,2,'36 boxes',21.3500,0,0,0,1,NULL),(6,'Grandma\'s Boysenberry Spread',3,2,'12 - 8 oz jars',25.0000,120,0,25,0,NULL),(7,'Uncle Bob\'s Organic Dried Pears',3,7,'12 - 1 lb pkgs.',30.0000,15,0,10,0,NULL),(8,'Northwoods Cranberry Sauce',3,2,'12 - 12 oz jars',40.0000,6,0,0,0,NULL),(9,'Mishi Kobe Niku',4,6,'18 - 500 g pkgs.',97.0000,29,0,0,1,NULL),(10,'Ikura',4,8,'12 - 200 ml jars',31.0000,31,0,0,0,NULL),(11,'Queso Cabrales',5,4,'1 kg pkg.',21.0000,22,30,30,0,NULL),(12,'Queso Manchego La Pastora',5,4,'10 - 500 g pkgs.',38.0000,86,0,0,0,NULL),(13,'Konbu',6,8,'2 kg box',6.0000,24,0,5,0,NULL),(14,'Tofu',6,7,'40 - 100 g pkgs.',23.2500,35,0,0,0,NULL),(15,'Genen Shouyu',6,2,'24 - 250 ml bottles',15.5000,39,0,5,0,NULL),(16,'Pavlova',7,3,'32 - 500 g boxes',17.4500,29,0,10,0,NULL),(17,'Alice Mutton',7,6,'20 - 1 kg tins',39.0000,0,0,0,1,NULL),(18,'Carnarvon Tigers',7,8,'16 kg pkg.',62.5000,42,0,0,0,NULL),(19,'Teatime Chocolate Biscuits',8,3,'10 boxes x 12 pieces',9.2000,25,0,5,0,NULL),(20,'Sir Rodney\'s Marmalade',8,3,'30 gift boxes',81.0000,40,0,0,0,NULL),(21,'Sir Rodney\'s Scones',8,3,'24 pkgs. x 4 pieces',10.0000,3,40,5,0,NULL),(22,'Gustaf\'s Knהckebrצd',9,5,'24 - 500 g pkgs.',21.0000,104,0,25,0,NULL),(23,'Tunnbrצd',9,5,'12 - 250 g pkgs.',9.0000,61,0,25,0,NULL),(24,'Guaranב Fantבstica',10,1,'12 - 355 ml cans',4.5000,20,0,0,1,NULL),(25,'NuNuCa Nu-Nougat-Creme',11,3,'20 - 450 g glasses',14.0000,76,0,30,0,NULL),(26,'Gumbהr Gummibהrchen',11,3,'100 - 250 g bags',31.2300,15,0,0,0,NULL),(27,'Schoggi Schokolade',11,3,'100 - 100 g pieces',43.9000,49,0,30,0,NULL),(28,'Rצssle Sauerkraut',12,7,'25 - 825 g cans',45.6000,26,0,0,1,NULL),(29,'Thringer Rostbratwurst',12,6,'50 bags x 30 sausgs.',123.7900,0,0,0,1,NULL),(30,'Nord-Ost Matjeshering',13,8,'10 - 200 g glasses',25.8900,10,0,15,0,NULL),(31,'Gorgonzola Telino',14,4,'12 - 100 g pkgs',12.5000,0,70,20,0,NULL),(32,'Mascarpone Fabioli',14,4,'24 - 200 g pkgs.',32.0000,9,40,25,0,NULL),(33,'Geitost',15,4,'500 g',2.5000,112,0,20,0,NULL),(34,'Sasquatch Ale',16,1,'24 - 12 oz bottles',14.0000,111,0,15,0,NULL),(35,'Steeleye Stout',16,1,'24 - 12 oz bottles',18.0000,20,0,15,0,NULL),(36,'Inlagd Sill',17,8,'24 - 250 g  jars',19.0000,112,0,20,0,NULL),(37,'Gravad lax',17,8,'12 - 500 g pkgs.',26.0000,11,50,25,0,NULL),(38,'Cפte de Blaye',18,1,'12 - 75 cl bottles',263.5000,17,0,15,0,NULL),(39,'Chartreuse verte',18,1,'750 cc per bottle',18.0000,69,0,5,0,NULL),(40,'Boston Crab Meat',19,8,'24 - 4 oz tins',18.4000,123,0,30,0,NULL),(41,'Jack\'s New England Clam Chowder',19,8,'12 - 12 oz cans',9.6500,85,0,10,0,NULL),(42,'Singaporean Hokkien Fried Mee',20,5,'32 - 1 kg pkgs.',14.0000,26,0,0,1,NULL),(43,'Ipoh Coffee',20,1,'16 - 500 g tins',46.0000,17,10,25,0,NULL),(44,'Gula Malacca',20,2,'20 - 2 kg bags',19.4500,27,0,15,0,NULL),(45,'Rרgede sild',21,8,'1k pkg.',9.5000,5,70,15,0,NULL),(46,'Spegesild',21,8,'4 - 450 g glasses',12.0000,95,0,0,0,NULL),(47,'Zaanse koeken',22,3,'10 - 4 oz boxes',9.5000,36,0,0,0,NULL),(48,'Chocolade',22,3,'10 pkgs.',12.7500,15,70,25,0,NULL),(49,'Maxilaku',23,3,'24 - 50 g pkgs.',20.0000,10,60,15,0,NULL),(50,'Valkoinen suklaa',23,3,'12 - 100 g bars',16.2500,65,0,30,0,NULL),(51,'Manjimup Dried Apples',24,7,'50 - 300 g pkgs.',53.0000,20,0,10,0,NULL),(52,'Filo Mix',24,5,'16 - 2 kg boxes',7.0000,38,0,25,0,NULL),(53,'Perth Pasties',24,6,'48 pieces',32.8000,0,0,0,1,NULL),(54,'Tourtiטre',25,6,'16 pies',7.4500,21,0,10,0,NULL),(55,'Pגtי chinois',25,6,'24 boxes x 2 pies',24.0000,115,0,20,0,NULL),(56,'Gnocchi di nonna Alice',26,5,'24 - 250 g pkgs.',38.0000,21,10,30,0,NULL),(57,'Ravioli Angelo',26,5,'24 - 250 g pkgs.',19.5000,36,0,20,0,NULL),(58,'Escargots de Bourgogne',27,8,'24 pieces',13.2500,62,0,20,0,NULL),(59,'Raclette Courdavault',28,4,'5 kg pkg.',55.0000,79,0,0,0,NULL),(60,'Camembert Pierrot',28,4,'15 - 300 g rounds',34.0000,19,0,0,0,NULL),(61,'Sirop d\'יrable',29,2,'24 - 500 ml bottles',28.5000,113,0,25,0,NULL),(62,'Tarte au sucre',29,3,'48 pies',49.3000,17,0,0,0,NULL),(63,'Vegie-spread',7,2,'15 - 625 g jars',43.9000,24,0,5,0,NULL),(64,'Wimmers gute Semmelknצdel',12,5,'20 bags x 4 pieces',33.2500,22,80,30,0,NULL),(65,'Louisiana Fiery Hot Pepper Sauce',2,2,'32 - 8 oz bottles',21.0500,76,0,0,0,NULL),(66,'Louisiana Hot Spiced Okra',2,2,'24 - 8 oz jars',17.0000,4,100,20,0,NULL),(67,'Laughing Lumberjack Lager',16,1,'24 - 12 oz bottles',14.0000,52,0,10,0,NULL),(68,'Scottish Longbreads',8,3,'10 boxes x 8 pieces',12.5000,6,10,15,0,NULL),(69,'Gudbrandsdalsost',15,4,'10 kg pkg.',36.0000,26,0,15,0,NULL),(70,'Outback Lager',7,1,'24 - 355 ml bottles',15.0000,15,10,30,0,NULL),(71,'Flרtemysost',15,4,'10 - 500 g pkgs.',21.5000,26,0,0,0,NULL),(72,'Mozzarella di Giovanni',14,4,'24 - 200 g pkgs.',34.8000,14,0,0,0,NULL),(73,'Rצd Kaviar',17,8,'24 - 150 g jars',15.0000,101,0,5,0,NULL),(74,'Longlife Tofu',4,7,'5 kg pkg.',10.0000,4,20,5,0,NULL),(75,'Rhצnbrהu Klosterbier',12,1,'24 - 0.5 l bottles',7.7500,125,0,25,0,NULL),(76,'Lakkalikצצri',23,1,'500 ml',18.0000,57,0,20,0,NULL),(77,'Original Frankfurter grne Soe',12,2,'12 boxes',13.0000,32,0,15,0,NULL);
/*!40000 ALTER TABLE `products` ENABLE KEYS */;
UNLOCK TABLES;



--
-- Table structure for table `orderdetails`
-- 

DROP TABLE IF EXISTS `orderdetails`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `orderdetails` (
  `OrderID` int NOT NULL,
  `ProductID` int NOT NULL,
  `UnitPrice` decimal(19,4) NOT NULL DEFAULT '0.0000',
  `Quantity` int NOT NULL DEFAULT '1',
  `Discount` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`OrderID`,`ProductID`),
   CONSTRAINT `fk_orderdetails_Orders`
    FOREIGN KEY (`OrderID`)
    REFERENCES `mynorthwind`.`orders` (`OrderID`) ON delete restrict ON update restrict,
    CONSTRAINT `fk_orderdetails_products`
    FOREIGN KEY (`ProductID`)
    REFERENCES `mynorthwind`.`products` (`ProductID`) ON delete restrict ON update restrict,
  KEY `OrderID` (`OrderID`),
  KEY `ProductID` (`ProductID`)
) ENGINE=InnoDB; -- DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orderdetails`
--

LOCK TABLES `orderdetails` WRITE;
/*!40000 ALTER TABLE `orderdetails` DISABLE KEYS */;
INSERT INTO `orderdetails` VALUES (10248,11,14.0000,12,0),(10248,42,9.8000,10,0),(10248,72,34.8000,5,0),(10249,14,18.6000,9,0),(10249,51,42.4000,40,0),(10250,41,7.7000,10,0),(10250,51,42.4000,35,0.15),(10250,65,16.8000,15,0.15),(10251,22,16.8000,6,0.05),(10251,57,15.6000,15,0.05),(10251,65,16.8000,20,0),(10252,20,64.8000,40,0.05),(10252,33,2.0000,25,0.05),(10252,60,27.2000,40,0),(10253,31,10.0000,20,0),(10253,39,14.4000,42,0),(10253,49,16.0000,40,0),(10254,24,3.6000,15,0.15),(10254,55,19.2000,21,0.15),(10254,74,8.0000,21,0),(10255,2,15.2000,20,0),(10255,16,13.9000,35,0),(10255,36,15.2000,25,0),(10255,59,44.0000,30,0),(10256,53,26.2000,15,0),(10256,77,10.4000,12,0);
/*!40000 ALTER TABLE `orderdetails` ENABLE KEYS */;
UNLOCK TABLES;

/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-07-23 13:52:51
