#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[]) {
  MYSQL* con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "", NULL, 0, NULL, 0) ==
      NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }

  if (mysql_query(con, "CREATE DATABASE test")) {
    if (strcmp(mysql_error(con),
               "Can't create database 'test'; database exists") == 0) {
      printf("Database is exists");
    } else {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
    }
  }
  mysql_close(con);
  con = mysql_init(NULL);

  if (mysql_real_connect(con, "localhost", "root", "", "test", 0, NULL, 0) ==
      NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }

  if (mysql_query(con, "DROP TABLE IF EXISTS users")) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }

  if (mysql_query(
          con,
          "CREATE TABLE users(id INT PRIMARY KEY AUTO_INCREMENT, username "
          "VARCHAR(255) UNIQUE, password VARCHAR(255), highScore INT DEFAULT 0)")) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }

    if (mysql_query(
            con,
            "CREATE TABLE questions(id INT PRIMARY KEY AUTO_INCREMENT, question VARCHAR(255), answer1 VARCHAR(255), answer2 VARCHAR(255), answer3 VARCHAR(255), answer4 VARCHAR(255), trueanswer VARCHAR(255), level INT)")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    if (mysql_query(
            con,
            "CREATE TABLE using_accounts(id INT PRIMARY KEY AUTO_INCREMENT, username VARCHAR(255) UNIQUE)")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

  if (mysql_query(
          con,
          "INSERT INTO users(username, password) VALUES('Audi', '52642')")) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }

  if (mysql_query(
            con,
            "INSERT INTO questions(question, answer1, answer2, answer3, answer4, trueanswer, level) "
            "VALUES('How many rings does Olympic flag have ?', 'A. Five', 'B. Six', 'C.Four', 'D.Ten', 'A','1'),"
            "('What did Erno Rubik invent in 1975 ?', 'A. Microscope ', 'B. Telegraph', 'C.Rubik''s Cube', 'D.Polygraph', 'D','1'),"
            "('Which country has won the most FIFA World Cups in football?', 'A. Argentina ', 'B. Spain', 'C.Japan', 'D.Brazil', 'B','1'),"
            "('Which of the following, is the best source of protein ?', 'A. Salad ', 'B. Fish', 'C.Cucumber', 'D.Grape','A','1'),"
            "('What kind of scientist was Euclid ?', 'A. Philosophist ', 'B. Chemist', 'C.Mathematic', 'D.Physician ', 'C','2'),"
            "('Which of the following, is the longest river in Europe ?', 'A. Ural ', 'B. Elbe', 'C.Oka', 'D.Volga', 'D','2'),"
            "('Which of the following, is the biggest moon of the Saturn ?', 'A. Titan ', 'B. Rhea', 'C.Hyperion', 'D.Iapetus ', 'A','2'),"
            "('Which of the following musicians is also known as King of POP ?', 'A. Frank zappa', 'B. Freddie mercury', 'C.George Michael', 'D.Michael Jackson', 'D' ,'2'),"
            "('What do you call someone who doesn''''t believe in god ?', 'A. Atheist ', 'B. Agnostic', 'C.Theist', 'D.Skeptic ', 'A','1'),"
            "('Which animal, is the fastest animal in the world ?', 'A. Lion ', 'B. Cheetah', 'C.Greyhound', 'D.Horse', 'B','3'),"
            "('What year did 9/11 happen ?', 'A. 1999 ', 'B. 2001', 'C.2004', 'D.2000', 'B' ,'3'),"
            "('Who were the defeated finalists at Euro 2008 ?', 'A. Germany ', 'B. England', 'C.France', 'D.Poland', 'A','3'),"
            "('How many independent countries border the Caspian sea ?', 'A. Four ', 'B. Six', 'C.Two', 'D.Five', 'D','3'),"
            "('What is the Closest Planet to Earth?', 'A. Venus ', 'B. Mars', 'C.Jupiter', 'D.Saturn', 'A','3'),"
            "('How many teeth do adult human have in their mouth ?', 'A. 30', 'B. 38', 'C. 32', 'D. 28', 'C', '1'),"
            "('What country declared independence from Serbia in 2008 ?',  'A. Albania', 'B. Kosovo', 'C. Montenegro', 'D. Macedonia', 'B','2'),"
            "('Who invented Mobile phone?', 'A. Martin Cooper', 'B. Alexander Graham Bell', 'C. Thomas Edison', 'D. Albert Einstein', 'A', '3'),"
            "('Which football club in England has won the most trophies ?', 'A. Liverpool', 'B. Chelsea', 'C. Arsenal', 'D. Manchester United', 'D', '1'),"
            "('Entomology is the science that studies ?','A. The formation of rocks', 'B. Behavior of human beings', 'C. Insects', 'D. Computers', 'C', '2'),"
            "('Grand Central Terminal, Park Avenue, New York is the world''s ?', 'A. Highest railway station', 'B. Largest railway station', 'C. Longest railway station', 'D. Largest airport', 'B', '3'),"
            "('Hitler party which came into power in 1933 is known as ?',  'A. Nazi Party', 'B. Labour Party', 'C. Ku-Klux-Klan', 'D. Democratic Party', 'A','1'),"
            "('Epsom (England) is the place associated with ?',  'A. Polo', 'B. Horse racing', 'C. Shooting', 'D. Snooker', 'B','2'),"
            "('First human heart transplant operation conducted by Dr. Christian Bernard on Louis Washkansky, was conducted in ?',  'A. 1965', 'B. 1964', 'C. 1969', 'D. 1967', 'D', '1'),"
            "('First Afghan War took place in ?', 'A. 1835', 'B. 1832', 'C. 1839', 'D. 1840', 'C', '2'),"
            "('First China War was fought between ?', 'A. China and France', 'B. China and Britain', 'C. China and Egypt', 'D. China and Greek', 'B', '3'),"
            "('Each year World Red Cross and Red Crescent Day is celebrated on ?',  'A. May 8', 'B. May 18', 'C. May 1', 'D. May 25', 'A','1'),"
            "('In which year of First World War Germany declared war on Russia and France ?', 'A. 1913', 'B. 1914', 'C. 1915', 'D. 1916', 'B', '2'),"
            "('In a normal human body, the total number of red blood cells is ?', 'A. 20 trillion', 'B. 10 trillion', 'C. 15 trillion', 'D. 30 trillion', 'D', '3'),"
            "('On a radio, stations are changed by using what control?', 'A. Tuning', 'B. Volume', 'C. Bass', 'D. Treble', 'A', '1'),"
            "('Which material is most dense?', 'A. Silver', 'B. Styrofoam', 'C. Butter', 'D. Gold', 'D', '2'),"
            "('Which state in the United States is largest by area?', 'A. Alaska', 'B. California', 'C. Texas', 'D. Hawaii', 'A', '3'),"
            "('What is Aurora Borealis commonly known as?', 'A. Fairy Dust', 'B. Northern Lights', 'C. Book of ages', 'D. a Game of Thrones main character', 'B', '1'),"
            "('Galileo was an Italian astronomer who ...', 'A. developed the telescope', 'B. discovered four satellites of Jupiter', 'C. discovered that the movement of pendulum produces a regular time measurement', 'D. All of the above', 'D', '2'),"
            "('Exposure to sunlight helps a person improve his health because ...', 'A. the infrared light kills bacteria in the body', 'B. resistance power increases', 'C. the pigment cells in the skin get stimulated and produce a healthy tan', 'D. the ultraviolet rays convert skin oil into Vitamin D', 'D', '3'),"
            "('Sir Thomas Fearnley Cup is awarded to ... ', 'A. a club or a local sport association for remarkable achievements', 'B. amateur athlete, not necessarily an Olympian', 'C. National Olympic Committee for outstanding work', 'D. None of the above', 'A', '1'),"
            "('When is the International Workers of Day?', 'A. 15th April', 'B. 12th December', 'C. 1st May', 'D. 1st August', 'C', '2'),"
            "('When did China test their first atomic device?', 'A. 1962', 'B. 1963', 'C. 1964', 'D. 1965', 'C', '3'),"
            "('When did Commander Robert Peary discover the North Pole?', 'A. 1904', 'B. 1905', 'C. 1908', 'D. 1909', 'D', '1'),"
            "('What is the population density of Kerala?', 'A. 819/sq. km', 'B. 602/sq. km', 'C. 415/sq. km', 'D. 500/sq. km', 'A', '2'),"
            "('What is the range of missile Akash?', 'A. 4 km', 'B. 25 km', 'C. 500 m to 9 km', 'D. 150 km', 'A', '3'),"
            "('In the U.S., if it is not Daylight Saving Time, is it what?', 'A. Borrowed time', 'B. Overtime', 'C. Standard time', 'D. Party time', 'B', '1'),"
            "('Which country is largest by area?', 'A. UK', 'B. USA', 'C. Russia', 'D. China', 'A', '2'),"
            "('Light Year is related to', 'A. energy', 'B. speed', 'C. distance', 'D. intensity', 'B', '3'),"
            "('What are the dimensions of A4 paper?', 'A. 8.3 x 11.7', 'B. 8.5 x 11', 'C. 30cm x 50cm', 'D. 8.5 x 14', 'A', '1'),"
            "('Lhasa airport at Tibet is the World', 'A. largest airport', 'B. highest airport', 'C. lowest airport', 'D. busiest airport', 'A', '2'),"
            "('What does the F stand for in FBI?', 'A. Foreign', 'B. Federal', 'C. Flappy', 'D. Face', 'B', '3'),"
            "('The US declared war on which country after the bombing of Pearl Harbor?', 'A. Japan', 'B. Russia', 'C. Germany', 'D. China', 'A', '1'),"
            "('When is the World of Diabetes Day?', 'A. 14th November', 'B. 11th December', 'C. 15th October', 'D. 1st July', 'A', '2'),"
            "('What is the S.I. unit of temperature?', 'A. Kelvin', 'B. Celsius', 'C. Centigrade', 'D. Fahrenheit', 'C', '3'),"
            "('Garampani sanctuary is located at', 'A. Junagarh, Gujarat', 'B. Diphu, Assam', 'C. Kohima, Nagaland', 'D. Gangtok, Sikkim', 'B', '1'),"
            "('When and where was weightlifting introduced in Olympics?', 'A. 1986 at Athens', 'B. 1988 at Seoul', 'C. 1924 at St. Louis', 'D. 1908 at London', 'A', '1'),"
            "('The American General who led the revolt against the British and declared American independence was', 'A. George Washington', 'B. Bill Clinto', 'C. George Bush', 'D. None of the above', 'A', '2'),"
            "('Which month has only 28 days (unless it is a leap year)?', 'A. March', 'B. September', 'C. June', 'D. Feburary', 'D', '2'),"
            "('Pythagoras was first to ____ the universal validity of geometrical theorem.', 'A. give', 'B. prove', 'C. both', 'D. None of the above', 'B', '2'),"
            "('The EPA urges people to produce less waste by engaging in efforts to reduce, reuse and what?', 'A. Recycle', 'B. Rewrap', 'C. Repossess', 'D. Retire', 'A', '2'),"
            "('What kind of animal traditionally lives in a sty?', 'A. Cow', 'B. Pig', 'C. Fox', 'D. Teenager', 'B', '2'),"
            "('Mahabaleshwar is located in', 'A. Maharashtra', 'B. Rajasthan', 'C. Madhya Pradesh', 'D. Himachal Pradesh', 'A', '2'),"
            "('Karl Marx ideology advocated', 'A. a classed unique society', 'B. a united society', 'C. a classed society', 'D. None of the above', 'C', '2'),"
            "('Numismatics is the study of', 'A. coins', 'B. numbers', 'C. stamps', 'D. space', 'A', '1'),"
            "('Of the blood groups A, B, AB and O, which one is transfused into a person whose blood group is A?', 'A. Group A only', 'B. Group B only', 'C. Group A and O', 'D. Group AB only', 'C', '1'),"
            "('When did France became Republic?', 'A. 1789 AD', 'B. 1798 AD', 'C. 1792 AD', 'D. 1729 AD', 'C', '1'),"
            "('Heavy Water Project (Talcher) and Fertilizer plant (Paradeep) are famous industries of', 'A. Orissa', 'B. Tamil nadu', 'C. Andhra Pradesh', 'D. Kerala', 'A', '1'),"
            "('Guwahati High Court is the judicature of', 'A. Nagaland', 'B. Arunachal Pradesh', 'C. Assam', 'D. All of the above', 'D', '1'),"
            "('In aviation, what does UFO stand for?', 'A. Unified Flying Object', 'B. Unitary Flinging Obsession', 'C. United Flag Opposition', 'D. Unidentified Flying Object', 'D', '1'),"
            "('What are the three primary colors?', 'A. Red, green, blue', 'B. Magenta, pink, cyan', 'C. Yellow, salmon, brown', 'D. White, grey, black', 'A', '1'),"
            "('In which of these household appliances would you find a lint screen?', 'A. Dishwasher', 'B. Microwave oven', 'C. Clothes dryer', 'D. Trash compactor', 'C', '2'),"
            "('Which of the following consumer goods is the Gerber Products Co. best known for?', 'A. Potato chips', 'B. Fine wines', 'C. Chewing gum', 'D. Baby Food', 'D', '2'),"
            "('Lal Bahadur Shastri is also known as', 'A. Guruji', 'B. Man of Peace', 'C. Punjab Kesari', 'D. Mahamana', 'B', '2'),"
            "('When and where was hockey introduced for women in Olympics?', 'A. 1908 at London', 'B. 1980 at Moscow', 'C. 1936 at Berlin', 'D. 1924 at Paris', 'B', '2'),"
            "('The headquarters of UN are situated at', 'A. New York, USA', 'B. Haque (Netherlands)', 'C. Geneva', 'D. Paris', 'A', '1'),"
            "('Hamid Karzai was chosen president of Afghanistan in', 'A. 2000', 'B. 2001', 'C. 2002', 'D. 2003', 'C', '1'),"
            "('Ecology deals with', 'A. Birds', 'B. Cell formation', 'C. Relation between organisms and their environment', 'D. Tissues', 'C', '3'),"
            "('What is the name of the largest freshwater lake in the world?', 'A. Lake Union', 'B. Lake Superior', 'C. Lake Largest', 'D. Lake Goodwin', 'A', '3'),"
            "('What is the national emblem of Canada?', 'A. Maple Leaf', 'B. Brown Bear', 'C. Maple Syrup', 'D. Waffle', 'A', '3'),"
            "('An albino gorilla usually has what color fur?', 'A. Brown', 'B. Black', 'C. White', 'D. Golden', 'C', '3'),"
            "('What was the first university in the United States', 'A. Harvard', 'B. University of Washington', 'C. Yale', 'D. Oxford', 'A', '2'),"
            "('The ozone layer restricts', 'A. Visible light', 'B. Infrared radiation', 'C. X-rays and gamma rays', 'D. Ultraviolet radiation', 'D', '3'),"
            "('When cream is separated from milk', 'A. the density of milk increases', 'B. the density of milk decreases', 'C. the density of milk remains unchanged', 'D. it becomes more viscous', 'A', '3'),"
            "('Oscar Awards were instituted in', 'A. 1968', 'B. 1929', 'C. 1901', 'D. 1965', 'B', '3'),"
            "('On a radio, stations are changed by using what control?', 'A. Tuning', 'B. Volume', 'C. Bass', 'D. Treble', 'A', '1'),"
            "('A college graduate who receives a B.S. degree holds what official title?', 'A. Bachelor of science', 'B. Business scholar', 'C. Baccalaureate staff', 'D. Brainy student', 'A', '1'),"
            "('Which of the following telephone area codes is not a toll-free call in the United States?', 'A. 800', 'B. 828', 'C. 877', 'D. 888', 'B', '3'),"
            "('What part of the human body does glaucoma directly affect?', 'A. Ear', 'B. Nose', 'C. Throat', 'D. Eye', 'D', '2'),"
            "('Which of these materials is used to make vests bulletproof?', 'A. Kevlar', 'B. Lycra', 'C. Gore-tex', 'D. Polystyrene', 'A', '1'),"
            "('College football of Independence Bowl is played in what city?', 'A. Philadelphia', 'B. Memphis', 'C. Shreveport', 'D. Tucson', 'C', '2'),"
            "('In Greek mythology, what is the relationship between Oedipus and Antigone?', 'A. Husband and wife', 'B. Mentor and student', 'C. Father and daughter', 'D. Mother and son', 'C', '2'),"
            "('The rococo style of art originated in what country?', 'A. France', 'B. Italy', 'C. Austria', 'D. Spain', 'A', '1'),"
            "('In Norse mythology, Mjolnir was the name of what?', 'A. Thor hammer', 'B. Odin horse', 'C. Sigmund sword', 'D. Loki magic necklace', 'A', '1'),"
            "('On July 12, 2000, Russia launched a rocket into space bearing the corporate logo of what company?', 'A. Intel', 'B. Reebok', 'C. Budweiser', 'D. Pizza Hut', 'C', '1'),"
            "('In the U.S., if it is not Daylight Saving Time, it is what?', 'A. Borrowed time', 'B. Overtime', 'C. Standard time', 'D. Party time', 'C', '2'),"
            "('Put your seat backs and tray tables into their full upright and locked position is usually heard where?', 'A. Grade school', 'B. Planetarium', 'C. Airplane', 'D. Thanksgiving dinner', 'C', '2'),"
            "('In U.S. personal ads, what do the letters ISO traditionally represent?', 'A. I am someone ordinary', 'B. In search of', 'C. I seek one', 'D. It seems odd', 'B', '3'),"
            "('A person who earns a Ph.D. is literally a certified doctor of what?', 'A. Photography', 'B. Pharmacology', 'C. Philosophy', 'D. Psychology', 'C', '3'),"
            "('British actor/comedian Rowan Atkinson plays what famous character?', 'A. Mr. Nut', 'B. Mr. Bean', 'C. Mr. Pea', 'D. Mr. Sprout', 'B', '3'),"
            "('What is the only Great Lake that lies wholly within the U.S.?', 'A. Lake Erie', 'B. Lake Huron', 'C. Lake Michigan', 'D. Lake Superior', 'C', '1'),"
            "('Acadia National Park is located in what U.S. state?', 'A. Maine', 'B. Michigan', 'C. Arkansas', 'D. Louisiana', 'A', '2'),"
            "('The National Hockey League of trophy for league of leading goal scorer is named for what player?', 'A. Wayne Gretzky', 'B. Maurice Richard', 'C. Gordie Howe', 'D. Mario Lemieux', 'B', '3'),"
            "('Reacting with virtually every other element, what is the most reactive chemical element?', 'A. Fluorine', 'B. Oxygen', 'C. Phosphorus', 'D. Sodium', 'A', '2'),"
            "('What taxonomic family do human beings belong to?', 'A. Chordata', 'B. Mammalia', 'C. Primate', 'D. Hominidae', 'D', '2'),"
            "('An albino gorilla usually has what color fur?', 'A. Brown', 'B. Black', 'C. White', 'D. Golden', 'C', '3'),"
            "('A serial story in which each installment ends at a point of suspense is called a what?', 'A. Ledge-hanger', 'B. Rock-hanger', 'C. Cliff-hanger', 'D. Clothes hanger', 'C', '3'),"
            "('U.S. battleships are traditionally named for what?', 'A. Presidents', 'B. Constellations', 'C. States', 'D. War heroes', 'C', '2'),"
            "('Athletic shoe maker Nike has its headquarters in what state?', 'A. New York', 'B. Washington', 'C. California', 'D. Oregon', 'D', '1'),"
            "('The Strait of Gibraltar connects the Atlantic Ocean and what sea?', 'A. Mediterranean', 'B. Red', 'C. North', 'D. Black', 'A', '3'),"
            "('A scientific barometer measures pressure in which of the following units?', 'A. Baroms', 'B. Farads', 'C. Angstroms', 'D. Millibars', 'D', '3'),"
            "('The active ingredient in antiperspirants is usually a salt of which element?', 'A. Sodium', 'B. Cadmium', 'C. Calcium', 'D. Aluminum', 'D', '2'),"
            "('What continent has the most countries?', 'A. Europe', 'B. Asia', 'C. Africa', 'D. South America', 'C', '3'),"
            "('What was the name of the first spacecraft to carry a human being into space?', 'A. Soyuz 4', 'B. Vostok 1', 'C. Salyut 3', 'D. Sputnik 10', 'B', '3'),"
            "('Which of the following consumer goods is the Gerber Products Co. best known for?', 'A. Potato chips', 'B. Fine wines', 'C. Chewing gum', 'D. Baby Food', 'D', '3'),"
            "('When did US astronauts Neil Armstrong and Edwin E. Aldrin land on the moon?', 'A. July 21, 1969', 'B. July 21, 1970', 'C. July 21, 1963', 'D. July 21, 1972', 'A', '1'),"
            "('When did 19 NATO members and 11 Partners for Peace join hands for peace plan for Kosovo Crisis?', 'A. 1999', 'B. 1989', 'C. 1979', 'D. 1969', 'A', '2'),"
            "('What is the national emblem of Canada?', 'A. Maple Leaf', 'B. Brown Bear', 'C. Maple Syrup', 'D. Waffle', 'A', '3'),"
            "('Which of these African countries is situated south of the equator?', 'A. Ethiopia', 'B. Nigeria', 'C. Zambia', 'D. Chad', 'B', '1'),"
            "('When did Yuri Alekseyevich Gagaris of Russia, the first man to reach space, reach space?', 'A. 1960', 'B. 1961', 'C. 1962', 'D. 1963', 'B', '1'),"
            "('Which of the following, is the largest company by revenue ?', 'A. Wal-Mart ', 'B. BP', 'C.Apple', 'D.Shell', 'A','2')")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

  mysql_close(con);
  exit(0);
}
