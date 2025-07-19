class ValidatedString:
    """A descriptor that enforces string type and auto-labels itself."""

    def __set_name__(self, owner, name):
        # This method is called automatically when the descriptor is assigned
        # to an attribute on a class.
        print(f"_set_name_ called: owner={owner.__name__}, name='{name}'")
        self.private_name = '_' + name
        # print(type())

    def __get__(self, obj, objtype=None):
        if obj is None:
            return self
        return getattr(obj, self.private_name)

    def __set__(self, obj, value):
        if not isinstance(value, str):
            raise TypeError("Value must be a string.")
        setattr(obj, self.private_name, value)


class Person:
    # The descriptor automatically knows its own name ('name')
    deepak = ValidatedString()
    # And here it knows its name is 'city'
    city = ValidatedString()


# --- Scenario ---
p = Person()
p.name = "Alice"
p.city = "London"

try:
    p.name = 123
except TypeError as e:
    print(f"Caught expected error: {e}")

print(f"Person's name: {p.name}")
print(f"Person's city: {p.city}")
print(f"Instance dictionary: {p.__dict__}")

