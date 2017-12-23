public namespace TestClass
{
    public class TestClass()
    {
        private IClassOne _classOne;
        private IClassTwo _classTwo;
        private IClassThree _classThree;
        
        public TestClass(IClassOne classOne, IClassTwo classTwo, IClassThree classThree)
        {
            _classOne = classOne;
            _classTwo = classTwo;
            _classThree = classThree;
        }   
    }
}
