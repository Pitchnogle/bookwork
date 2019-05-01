def print_lol(the_list):
  """
  This function prints out a list recursively where each line will contain one
  entry from the list which may be a nested list.
  """
  for each_item in the_list:
    if isinstance(each_item, list):
      print_lol(each_item)
    else:
      print(each_item)