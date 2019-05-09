import pickle
from athlete_list import athlete_list

def get_coach_data(filename):
    try:
        with open(filename) as f:
            data = f.readline()
        tmp = data.strip().split(',')
        return(athlete_list(tmp.pop(0), tmp.pop(0), tmp))
    except IOError as ioerr:
        print('File error: ' + str(ioerr))
        return(None)

def put_to_store(files_list):
  all_athletes = {}
  for each_file in files_list:
    athlete = get_coach_data(each_file)
    all_athletes[athlete.name] = athlete

  try:
    with open('athletes.p', 'wb') as athlete_file:
      pickle.dump(all_athletes, athlete_file)
  except IOError as ioerr:
    print('File Error (put_and_store): ' + str(ioerr))

  return (all_athletes)

def get_from_store():
  all_athletes = {}
  try:
    with open('athletes.p', 'rb') as athlete_file:
      all_athletes = pickle.load(athlete_file)
  except IOError as ioerr:
    print('File Error (get_from_store): ', str(ioerr))

  return (all_athletes)

